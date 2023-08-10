#include "parser.tab.h"
#include <stdio.h>
#include <string.h>

extern FILE* yyin;

void set_identifier(char* data)
{
    printf("set_identifier %s\n", data);
}

int main()
{
    FILE* fp = fopen("./eth.fa", "r");
    if (fp == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    yyin = fp;
    yyparse();
    fclose(yyin);

    return 0;
}
