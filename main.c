#include <stdio.h>
#include <stdlib.h>
#include "phoneBookFunc.h"

int main()
{
    char input[50],temp;
    printf("Welcome to our Phonebook\nEnter H for the list of commands\n");
    /*printf("\t\t               _.===========================._\n");
    printf("\t\t            .'\`  .-  - __- - - -- --__--- -.  \`'.\ \n");
    printf("\t\t        __ / ,'\`     _|--|_________|--|_     \`'. \\ \n");
    printf("\t\t      /'--| ;    _.'\\ |  '         '  | /'._    ; |\n");
    printf("\t\t     //   | |_.-' .-'.'    -  -- -    '.'-. '-._| |\n");
    printf("\t\t    (\\)   \\\"\` _.-\` /                     \\ \`-._ \`\"/\n");
    printf("\t\t    (\\)    \`-\`    /      .---------.      \\    \`-\`\n");
    printf("\t\t    (\\)           |      ||1||2||3||      |\n");
    printf("\t\t   (\\)            |      ||4||5||6||      |\n");
    printf("\t\t  (\\)             |      ||7||8||9||      |\n");
    printf("\t\t (\\)           ___|      ||*||0||#||      |\n");
    printf("\t\t (\\)          /.--|      '---------'      |\n");
    printf("\t\t  (\\)        (\\)  |\\_  _  __   _   __  __/|\n");
    printf("\t\t (\\)        (\\)   |                       |\n");
    printf("\t\t(\\)_._._.__(\\)    |                       |\n");
    printf("\t\t (\\\\\\\\jgs\\\\\\)      '.___________________.'\n");
    printf("\t\t  '-'-'-'--'\n\n");*/

    while(1)
    {

        printf("\n");
        scanf("%s",input);
        temp = errorInput (input) ;
        switch(temp)
        {
            case 'L':
            case 'l':
                loads();
                //p = load(&n);
                break;
            case 'H':
            case 'h':
                printHelp();
                break;
            case 'P':
            case 'p':
                printSort();
                break;
            case 'A':
            case 'a':
                addRecord();
                break;
            case 'S':
            case 's':
                save();
                break;
            case 'D':
            case 'd':
                deleteEntry();
                break;
            case 'E':
            case 'e':
                exitCode();
                break;
            case 'Q':
            case 'q':
                query();
                break;
            case 'M':
            case 'm':
                modify();
                break;
        };
    }
    return 0;
}
