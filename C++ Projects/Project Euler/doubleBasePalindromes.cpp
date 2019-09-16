#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool isPalindromic(unsigned long long num) {

    vector<int> digit;
    while(num > 0) {
        digit.push_back(num % 10);
        num /= 10;
    }
    for(int i = 0; i < digit.size(); i++) {
        if(digit[i] != digit[digit.size() - i - 1])
            return false;
    }
    return true;

}

bool binaryPalindrome(int num) {

    int msb;
    for(int i = 0; i < 20; i++) {
        if(num >= pow(2, i)) {
            msb = i;
        }
    }

    bool binary[msb + 1];
    for(int i = 0; i < msb + 1; i++)
        binary[i] = 0;

    for(int i = msb; i >= 0; i--) {
        if(num >= pow(2, i)) {
            num -= pow(2, i);
            binary[i] = 1;
        }
    }

    for(int i = 0; i <= msb; i++) {
        if(binary[i] != binary[msb - i])
            return 0;
    }

    return 1;

}

int main() {

    int sum = 0;
    for(int i = 1; i < 1000000; i+=2) {
        if(isPalindromic(i)) {
            if(binaryPalindrome(i)) {
                sum += i;
            }
        }
    }
    cout << "The sum of the numbers under 1,000,000 whose base 10 and base 2 representations are both palindromes is " << sum << ".\n";

    return 0;

}