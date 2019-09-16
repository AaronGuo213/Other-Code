/*Given an array of non-negative integers, you are initially positioned at the
first index of the array.
Each element in the array represents your maximum jump length at that
position.
Determine if you are able to reach the last index.*/

#include <iostream>

using namespace std;

int main() {

    bool answer = true, check = false;
    int islands;
    cin >> islands;
    int island[islands];

    for(int i = 0; i < islands; i++) {
        cin >> island[i];
    }

    for(int i = 0; i < islands; i++) {

        if(island[i] == 0) {

            for(int j = 0; j < i; j++) {
            
                if(island[j] + j > i)
                    check = true;

            }

            if(!check)
                answer = false;

        }

        check = false;

    }

    cout << answer;

}