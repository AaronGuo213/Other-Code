#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double number;
    double denominator = 2;
    double numerator;
    double checker = 0;

    cout << "What is your decimal that you want to be converted?" << endl;
    cin >> number;

    while (checker == 0){
        numerator = number * denominator;
        if (numerator % 1 == 0)
            checker = 1;
        else
            denominator +=;
    }

    cout << "Your fraction is " << numerator << "/" << denominator << "." << endl;
}
