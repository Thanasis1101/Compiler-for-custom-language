#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

FILE *finalSrcFile;
char includedFileNames[50][50];
int countIncludedFiles = 0;
char* includeStatement = "include ";
int lengthOfIncludeStatement;

void processFile(char *inputFileName){

    char libPath[100];
    strcpy(libPath, "C:\\cmpl\\lib\\");

    FILE* file = fopen(inputFileName, "r");

    if (!file){ // Check file existance

        strcat(libPath, inputFileName);
        file = fopen(libPath, "r");

        if (!file){

            printf("File '%s' not found.\n", inputFileName);
            exit(1);

        }

    }

    // Check if file already included
    int i;
    for (i=0; i<countIncludedFiles; i++){
        if (strcmp(includedFileNames[i], inputFileName) == 0){

            printf("File '%s' already included.\n", inputFileName);
            exit(1);

        }
    }

    strcpy(includedFileNames[countIncludedFiles++], inputFileName);

    int countSpaces;
    char line[256];
    char firstNLetters[lengthOfIncludeStatement+2];
    char includedFileName[50];
    char *pos;

    while (fgets(line, sizeof(line), file)) {

        countSpaces = 0;
        while (isspace(line[countSpaces])){
            countSpaces++;
        }
        strncpy(firstNLetters, line+countSpaces, lengthOfIncludeStatement);

        firstNLetters[lengthOfIncludeStatement] = 0;
        if (strcmp(firstNLetters, includeStatement) == 0){
            // found include

            strcpy(includedFileName, line + lengthOfIncludeStatement + countSpaces); // get the name of the file to be included
            if ((pos=strchr(includedFileName, '\n')) != NULL)
                *pos = '\0'; // replace \n with \0

            //printf("!%s!\n", includedFileName);
            processFile(includedFileName);

        } else {
            fprintf(finalSrcFile, "%s", line);
        }
    }
    /* may check feof here to make a difference between eof and io failure -- network
       timeout for instance */

    fprintf(finalSrcFile, "\n");

    fclose(file);

}

int main(int argc, char *argv[])
{



    if (argc>1){

        lengthOfIncludeStatement = strlen(includeStatement);

        char* srcFileName = argv[1];

        finalSrcFile = fopen("C:\\cmpl\\Final.code", "w+");
        processFile(srcFileName);
        fclose(finalSrcFile);


    } else {
        printf("No source file specified.\n");
    }


    return 0;
}
