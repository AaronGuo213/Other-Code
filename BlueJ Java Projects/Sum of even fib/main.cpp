#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a = 1;
    int b = 1;
    int c;
    int limit;
    int sum = 0;

    cout << "What is the limit?" << endl;
    cin >> limit;

    while (c <= limit){
        c = a + b;
        if (c % 2 == 0)
            sum = sum + c;
        if (a >= b)
            b = c;
        else
            a = c;
    }

    cout << "The sum of the even fibonacci numbers less or equal to " << limit << " is " << sum << "." << endl;
    return 0;}
