#include <iostream>
#include<string>
using namespace std;

bool checkPalindrome(int num) {

    string n = to_string(num);
    for(int i = 0; i < n.length(); i++) {
        if(n.at(i) != n.at(n.length() - i - 1))
            return false;
    }
    return true;

}

int main() {

    int bigBoi = 0;
    for(int i = 990; i > 100; i -= 11) {

        for(int j = 999; j > 99; j--) {

            if(checkPalindrome(i * j) && i * j > bigBoi)
                bigBoi = i * j;

        }

    }
    cout << "The largest pallindrome that is a product of two 3 digit numbers is " << bigBoi << endl;

}