/*Given an array, you must increment any duplicate elements until all its
elements are unique. In addition, the sum of its elements must be the
minimum possible within the rules. For example, if arr = [3, 2, 1, 2, 7],
then arr = [3, 2, 1, 4, 7] and its elements sum to a minimal value of
3 + 2 + 1 + 4 + 7 = 17.*/

#include <iostream>

using namespace std;

int main() {

    int n, sum = 0;
    cin >> n;
    int num[n];
    for(int i = 0; i < n; i++)
        cin >> num[i];
    
    for(int i = 0; i < n; i++) {

        for(int j = 0; j < n; j++) {

            if(j == i)
                j++;

            if(num[i] == num[j]) {

                num[i]++;
                j = 0;

            }

        }

    }

    for(int i = 0; i < n; i++)
        sum += num[i];

    cout << sum;

}