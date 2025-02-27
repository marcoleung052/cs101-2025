#include <stdio.h>

int main()
{
    int num = 12345;
    int sum = 0;
    int firstDigit,lastDigit;
    lastDigit=num%10;
    firstDigit=num;
    while(firstDigit>=10){
        firstDigit=firstDigit/10;
    }
    sum=firstDigit+lastDigit;
    printf("sun = %d",sum);
    return 0;
}
