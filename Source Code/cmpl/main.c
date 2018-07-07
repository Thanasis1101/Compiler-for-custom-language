#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void removeExtension(char* mystr) {
    char *lastdot;
    if (mystr == NULL)
         return;
    lastdot = strrchr (mystr, '.');
    if (lastdot != NULL)
        *lastdot = '\0';
}

int main(int argc, char *argv[])
{
    if (argc>1){

        char srcName[40];

        int i, result;
        for (i=1; i<argc; i++){

            strcpy(srcName, argv[i]);
            printf("\nCompiling '%s' ...\n", srcName);

            char preprocessCommand[40];
            sprintf(preprocessCommand, "preprocessor %s\n", srcName);
            result = system(preprocessCommand); // Preprocess Source Code

            if (result == 0){

                char compileCommand[40];
                sprintf(compileCommand, "Compiler.exe < C:\\cmpl\\Final.code\n");
                result = system(compileCommand); // Compile Source Code

                if (result == 0){

                    removeExtension(srcName);

                    system("copy C:\\cmpl\\AssemblyData.asm+C:\\cmpl\\AssemblyCode.asm C:\\cmpl\\AssemblyFinal.asm > NUL"); // Combine data and code section
                    system("nasm -f win32 C:\\cmpl\\AssemblyFinal.asm -o C:\\cmpl\\AssemblyFinal.obj"); // Create Assembly Object

                    char createExeCommand[40];
                    sprintf(createExeCommand, "gcc -m32 -o %s.exe C:\\cmpl\\AssemblyFinal.obj", srcName);
                    system(createExeCommand); // Create exe

                    system("del C:\\cmpl\\AssemblyData.asm");
                    system("del C:\\cmpl\\AssemblyCode.asm");
                    system("del C:\\cmpl\\AssemblyFinal.asm");
                    system("del C:\\cmpl\\AssemblyFinal.obj");

                    printf("Succesfully created '%s.exe'.\n", srcName);

                } else {
                    printf("Compilation of '%s' failed.\n", srcName);
                }


            } else {
                printf("Compilation of '%s' failed.\n", srcName);
            }

            system("del C:\\cmpl\\Final.code");


        }

    } else {
        printf("No source file specified.\n");
    }
    return 0;
}
