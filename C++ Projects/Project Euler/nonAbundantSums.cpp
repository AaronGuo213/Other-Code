#include <iostream>
#include <vector>
using namespace std;

int sumOfFactors(int num) {

    int sum = 1;
    for(int i = 2; i * i <= num; i++) {
        if(num % i == 0)
            sum += i + num / i;
        if(i * i == num)
            sum -= i;
    }

    return sum;

}

vector<int> findAbundantNums(int limit) {

    vector<int> num(0);
    for(int i = 1; i < limit; i++) {
        if(sumOfFactors(i) > i)
            num.push_back(i);
    }

    return num;

}

int main() {

    vector<int> abundantNum = findAbundantNums(28123);
    int sum = 0, low = 0, high, tempSum = 0;
    bool sumFound = false;
    for(int i = 1; i < 28123; i++) {

        low = 0;
        high = i < abundantNum.size() ? i : abundantNum.size() - 1;
        sumFound = false;
        tempSum = 0;
        while(low <= high) {
            tempSum = abundantNum[low] + abundantNum[high];
            if(tempSum == i) {
                sumFound = true;
                break;
            }
            else if(tempSum < i)
                low ++;
            else 
                high --;
            
        }
        if(!sumFound)
            sum += i;

    }
    cout << "The sum of all of the numbers that cannot be expressed as a sum of two abundant numbers is " << sum << ".\n";

    return 0;

}