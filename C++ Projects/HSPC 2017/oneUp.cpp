/*Given an integer encoded as an array of its digits, that is, 1234
= [1,2,3,4], compute the integer+1 and return it in an array of
digits.*/

#include <iostream>
#include <math.h>

using namespace std;

int main() {

    int n, num = 0;
    string answer;
    cin >> n;
    int a[n];

    for(int i = 0; i < n; i++) {

        cin >> a[i];
        num += pow(10, n - i - 1) * (a[i]);

    }

    num++;

    answer = to_string(num);

    for(int i = 0; i < answer.length(); i++) {

        cout << answer.at(i) << "\n";

    }

}