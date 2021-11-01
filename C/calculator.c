#include <stdio.h>

int main(int argc, char const *argv[])
{
    char operator;
    float operand1, operand2, result;

    printf("Enter operation : (ex : 1+1) >> ");
    scanf("%f%c%f", &operand1, &operator, &operand2);

    switch (operator){
        case '+':
            result = operand1 + operand2;
            break;
        case '-':
            result = operand1 - operand2;
            break;
        case '*':
            result = operand1 * operand2;
            break;
        case '/':
            result = operand1 / operand2;
            break;
        default:
            result = 0;
            break;
    }

    printf("Result : %.2f\n", result);
    return 0;
}
