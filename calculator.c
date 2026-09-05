#include <stdio.h>
#include <string.h>

#define MAX_LINE 256

int main()
{
    char line[MAX_LINE];

    printf("Simple Calculator\n");
    printf("Enter an expression (e.g. 3 + 4), or 'q' to quit.\n");

    while (1)
    {
        double a, b, result;
        char op;
        char cmd[8];

        printf("\n> ");

        /* Read a whole line, so bad input never gets stuck in the buffer. */
        if (fgets(line, MAX_LINE, stdin) == NULL)
        {
            printf("\nBye.\n");
            break;
        }

        if (sscanf(line, "%7s", cmd) != 1)
        {
            continue; /* empty line: just ask again */
        }

        if (strcmp(cmd, "q") == 0 || strcmp(cmd, "quit") == 0 ||
            strcmp(cmd, "exit") == 0)
        {
            printf("Bye.\n");
            break;
        }

        if (sscanf(line, "%lf %c %lf", &a, &op, &b) != 3)
        {
            printf("Invalid input. Expected: <number> <operator> <number>\n");
            continue;
        }

        switch (op)
        {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            if (b == 0)
            {
                printf("Error: division by zero.\n");
                continue;
            }
            result = a / b;
            break;
        default:
            printf("Error: unknown operator '%c'.\n", op);
            continue;
        }

        printf("%g %c %g = %g\n", a, op, b, result);
    }

    return 0;
}
