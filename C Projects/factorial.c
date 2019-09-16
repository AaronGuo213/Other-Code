#include <stdio.h>

int factorial(int n);

int factorial(int n) {

    if(n <= 1)
        return 1;
    else
        return n * factorial(n - 1);

}

int main() {

    int n = 5, product;
    n = n > 19 ? 19 : n;
    n = n < 1 ? 1 : n;
    product = factorial(n);
    printf("%d! is equal to %d.", n, product);

}