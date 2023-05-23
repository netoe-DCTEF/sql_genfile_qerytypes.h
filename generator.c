#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define FILENAME "sql_qrytypes.h"
#define COMMENT_0 "This file is responsible for documenting the SQL functions."
#define COMMENT_1 "Query Basic Types:"
#define COMMENT_2 "Query \"Functions:\""
#define COMMENT_3 "Query Complements:"

int i = 0;
char *data[] = {
    "CREATE_TABLE",
    "INNER_JOIN",
    "OUTTER_JOIN",
    "LEFT_JOIN",
    "RIGHT_JOIN",
    "DROP_TABLE",
    "CREATE_DATABASE",
    "ALTER_DATABASE",
};

char *types_of_query[] =
    {
        "SELECT",
        "DELETE",
        "UPDATE",
        "INSERT",
};

char *queries_complements[] =
    {
        "WHERE",
        "ORDER_BY",
        "INTO"
        "ALL",
        "FROM",
        "GROUP_BY",
};

int main(void)
{
    int i = 0;
    int aux = 0;
    FILE *file = fopen(FILENAME, "w");

    fprintf(file, "/*%s*/\n", COMMENT_0);
    fprintf(file, "/*%s*/\n", COMMENT_1);

    for (i = 0; i < strlen(*data); i++)
    {
        fprintf(file, "#define %s %d\n", data[i], aux + i);
    }

    fprintf(file, "/*%s*/\n", COMMENT_2);
    aux += i;

    for (i = 0; i < strlen(*types_of_query); i++)
    {
        fprintf(file, "#define %s %d\n", types_of_query[i], aux + i);
    }

    fprintf(file, "/*%s*/\n", COMMENT_3);
    aux += i;

    for (i = 0; i < strlen(*queries_complements); i++)
    {
        fprintf(file, "#define %s %d\n", types_of_query[i], aux + i);
    }

    fclose(file);
    return 0;
}
