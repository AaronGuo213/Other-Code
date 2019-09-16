#include <stdio.h>

int main() {

    char str_1[] = "String 1";
    char* my_ptr = str_1;
    int length = 0;
    while(*my_ptr != '\0') {
        my_ptr ++;
        length ++;
    }

    printf("Length is %d", length);

}