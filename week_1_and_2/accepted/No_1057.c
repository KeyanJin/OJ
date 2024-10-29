#include <stdio.h>

int main(void)
{
    int num1,num2;
    char operator;
    scanf("%d %d %c",&num1,&num2,&operator);    
    switch (operator)
    {
    case '+':
        printf("%d",num1 + num2);
        break;
    case '-':
        printf("%d",num1 - num2);
        break;
    case '*':
        printf("%d",num1 * num2);
        break;
    case '/':
        if(num2 == 0)
        {
            printf("Divided by zero!");
            break;
        }
        else
        {
            printf("%d",num1 / num2);
            break;
        }
    default:
        printf("Invalid operator!");
        break;
    }
    return 0;
}