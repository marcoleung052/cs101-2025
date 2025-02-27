#include <stdio.h>

int main()
{
    unsigned char i =201;
    unsigned char j =221;
    unsigned char k =0;
    // k=(i+j)/2;
    // k/=2;
    k=i/2+j/2;
    if (i%2==1&&j%2==1){
        k++;
    }
    printf("(%d + %d)/2 = %d\n",i,j,k);
    return 0;
}
