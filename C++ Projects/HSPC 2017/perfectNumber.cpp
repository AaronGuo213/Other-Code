/*A positive integer is a perfect number if it is equal to the sum its
positive divisors less than itself. Given a positive integer, confirm
whether the number is a perfect number using 1 as True, 0 as
False.*/

#include <iostream>

using namespace std;

int main() {

    int number, sum = 0;
    bool answer = false;
    cin >> number;

    for(int i = 1; i < number - 1; i++) {

        if(number % i == 0)
            sum += i;

    }

    if(sum == number)
        answer = true;

    std::cout << answer;

}