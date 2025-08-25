
#include <stdio.h>

int main(){

    int i;  // loop counter
    int num = 5;
    int sum = 0;
    
    for (i = 0; i <= 5; ++i){
        printf("Loop count is: %d%6d\n", i, sum);
        sum += num;
        printf("Loop count is: %d%6d\n", i, sum);
    }

    return 0;
}