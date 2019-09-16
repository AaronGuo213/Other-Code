#include <iostream>
#include <time.h>
using namespace std;

int rand7() {

    return rand() % 7 + 1;

}

int rand5() {

    int rtn = rand7();
    while(rtn > 5)
        rtn = rand7();
    return rtn;

}

int main() {

    int sum = 0;
    srand(time(NULL));
    for(int i = 0; i < 1000000; i++) {
        sum += rand5();
    }
    cout << sum;

}