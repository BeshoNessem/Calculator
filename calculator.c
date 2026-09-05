#include <stdio.h>

int main()
{
    double a, b, result;
    char op;

    printf("Simple Calculator\n");
    printf("Enter an expression (e.g. 3 + 4): ");

    if (scanf("%lf %c %lf", &a, &op, &b) != 3)
    {
        printf("Invalid input.\n");
        return 1;
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
            return 1;
        }
        result = a / b;
        break;
    default:
        printf("Error: unknown operator '%c'.\n", op);
        return 1;
    }

    printf("%g %c %g = %g\n", a, op, b, result);
    return 0;
}
