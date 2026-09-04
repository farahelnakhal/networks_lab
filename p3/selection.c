#include <stdio.h>

int main(){
    int n;

    printf("Please enter a number: ");
    scanf("%d", &n);

    if (n%3 == 0)
        printf("foo");
    if (n%5 == 0)
        printf("bar");
    printf("\n");

}