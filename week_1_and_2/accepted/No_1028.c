#include <stdio.h>

int main(void)
{
    char ch;
    scanf("%c",&ch);
    printf("  %c\n",ch);
    printf(" %c%c%c\n",ch,ch,ch);
    printf("%c%c%c%c%c\n",ch,ch,ch,ch,ch);
    printf(" %c%c%c\n",ch,ch,ch);
    printf("  %c\n",ch);

    return 0;
}