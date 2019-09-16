#include <iostream>
#include <vector>
using namespace std;

vector<int> carry(vector<int> digit) {

    for(int i = 0; i < digit.size(); i++) {
        if(digit[i] >= 10) {
            digit[i] -= 10;
            digit[i + 1] ++;
        }
    }
    //cout << "carried\n";

    return digit;

}

vector<int> timesTwo(vector<int> digit) {

    for(int i = 0; i < digit.size(); i++) {
        digit[i] *= 2;
    }
    //cout << "doubled\n";

    return digit;

}

int sumOfDigits(vector<int> digit) {

    int sum = 0;
    for(int i = 0; i < digit.size(); i++)
        sum += digit[i];

    return sum;

}

int main() {

    vector<int> num(1000);
    num[0] = 1;
    for(int i = 1; i < num.size(); i++)
        num[i] = 0;

    for(int i = 0; i < 1000; i++) {
        num = timesTwo(num);
        num = carry(num);
    }

    cout << "The sum of the digits of 2^1000 is " << sumOfDigits(num) << ".\n";

}