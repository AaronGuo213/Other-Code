#include <stdio.h>

int main() {

    int foo = 314;
    int bar = 156;
    printf("foo = %d, bar = %d\n", foo, bar);
    
    foo = foo ^ bar;
    bar = bar ^ foo;
    foo = foo ^ bar;
    printf("foo = %d, bar = %d\n", foo, bar);

}