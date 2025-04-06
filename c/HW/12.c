#include <stdio.h>
#include <string.h>
 
//.\my_program -std=c++20 -Wall -Wpedantic -Wextra a.c b.hxx c.cpp -Werror -o output_file -I /usr/local/boost_1_80_0/
//-std=c++20 -Wall -Wpedantic -Wextra a.c b.hxx c.cpp -Werror -o output_file -I /usr/local/boost_1_80_0/ D.C D.hpp D.cpp -std=gnu17 -Wall -Wpedantic -Wextra -Werror -o output_file -I /usr/local/boost_1_80_0/

int main(int argc, char **argv) {
    for (int i = 1; i < argc; ++i) {
        if (argv[i][0] == '-' && argv[i][1] == 'W' && argv[i][2] == 'a' && argv[i][3] == 'l' && argv[i][4] == 'l'){
            printf("-Wall: Enable all the warnings about constructions that some users consider questionable, and that are easy to avoid (or modify to prevent the warning).\n");
        }
        else if (argv[i][0] == '-' && argv[i][1] == 'W' && argv[i][2] == 'p' && argv[i][3] == 'e' && argv[i][4] == 'd'){
            printf("-Wpedantic: Issue all the warnings demanded by strict ISO C and ISO C++ and reject all programs that use forbidden extensions.\n");
        }
        else if (argv[i][0] == '-' && argv[i][1] == 'W' && argv[i][2] == 'e' && argv[i][3] == 'x'){
            printf("-Wextra: Enable some extra warning flags that are not enabled by -Wall.\n");
        }
        else if (argv[i][0] == '-' && argv[i][1] == 'W' && argv[i][2] == 'e' && argv[i][3] == 'r'){
            printf("-Werror: Make all warnings into errors.\n");
        }
        else if (argv[i][0] == '-' && argv[i][1] == 'o'){
            printf("-o ");
            i++;
            printf("%s: Place the primary output in file %s.\n", argv[i], argv[i]);
        }
        else if(argv[i][0] == '-' && argv[i][1] == 'I'){
            printf("-I ");
            i++;
            printf("%s: Add the directory %s to the list of directories to be searched for header files during preprocessing.\n", argv[i], argv[i]);
        }
        else if(argv[i][0] == '-' && argv[i][1] == 's' && argv[i][2] == 't' && argv[i][3] == 'd'){
            if (argv[i][5] == 'c' && argv[i][6] != '+'){
                printf("%s: Set the language standard to ISO C%d%d.\n", argv[i], argv[i][6] -48, argv[i][7]-48);
            }
            else if (argv[i][5] == 'c' && argv[i][6] == '+' && argv[i][7] == '+'){
                printf("%s: Set the language standard to ISO C++%d%d.\n", argv[i], argv[i][8]-48, argv[i][9]-48);
            }
            else if (argv[i][5] == 'g' && argv[i][6] == 'n' && argv[i][7] == 'u' && argv[i][8] == '+' && argv[i][9] == '+'){
                printf("%s: Set the language standard to GNU dialect of C++%d%d.\n", argv[i], argv[i][10]-48, argv[i][11]-48);
            }
            else{
                printf("%s: Set the language standard to GNU dialect of C%d%d.\n", argv[i], argv[i][8]-48, argv[i][9]-48);
            }
        }
        else{
            if (argv[i][strlen(argv[i])-1] == 'c' && argv[i][strlen(argv[i])-2] == '.'){
                printf("%s: C source code as input file.\n", argv[i]);
            }
            else if (argv[i][strlen(argv[i])-1] == 'h' && argv[i][strlen(argv[i])-2] == '.'){
                printf("%s: C/C++ header file as input file.\n", argv[i]);
            }
            else if (argv[i][strlen(argv[i])-1] == 'p' && argv[i][strlen(argv[i])-2] == 'p' && argv[i][strlen(argv[i])-3] == 'c' && argv[i][strlen(argv[i])-4] == '.'){
                printf("%s: C++ source code as input file.\n", argv[i]);
            }
            else if (argv[i][strlen(argv[i])-1] == 'C' && argv[i][strlen(argv[i])-2] == '.'){
                printf("%s: C++ source code as input file.\n", argv[i]);
            }
            else if (argv[i][strlen(argv[i])-1] == 'c' && argv[i][strlen(argv[i])-2] == 'c' && argv[i][strlen(argv[i])-3] == '.'){
                printf("%s: C++ source code as input file.\n", argv[i]);
            }
            else if (argv[i][strlen(argv[i])-1] == 'x' && argv[i][strlen(argv[i])-2] == 'x' && argv[i][strlen(argv[i])-3] == 'c' && argv[i][strlen(argv[i])-4] == '.'){
                printf("%s: C++ source code as input file.\n", argv[i]);
            }
            else{
                printf("%s: C++ header file as input file.\n", argv[i]);
            }
        }
    }
 
    return 0;
}