#include <stdio.h>

int main()
{
    int n=15,i=0;
    while(n){
        if (n%2==1){
            i++;
        }
        n/=2;
    }
    printf("%d",i);
    return 0;
}
