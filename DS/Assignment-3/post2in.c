#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char stack[50];
int top = -1;

char *strrev(char *str)
{
    if (!str || ! *str)
        return str;

    int i = strlen(str) - 1, j = 0;

    char ch;
    while (i > j)
    {
        ch = str[i];
        str[i] = str[j];
        str[j] = ch;
        i--;
        j++;
    }
    return str;
}

void push(char ch)
{
    stack[++top] = ch;
}
char pop()
{
    return stack[top--];
}
void convert(char exp[])
{
    int l, i, j = 0;
    char a, b, op, tmp[20];
    strrev(exp);
    l = strlen(exp);
    for (i = 0; i < 50; i++)
        stack[i] = '\0';
    printf("The Infix expression is : ");
    for (i = 0; i < l; i++)
    {
        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
        {
            push(exp[i]);
        }
        else
        {
            tmp[j++] = exp[i];
            tmp[j++] = pop();
        }
    }
    tmp[j] = exp[top--];
    strrev(tmp);
    puts(tmp);
}
 
int main()
{
    char exp[50]; 
    convert(exp);
    return 0;
}

