#include <iostream>

using namespace std;

int main() {

    bool answer = false;
    int n, k;
    cin >> n;
    int num[n];
    for(int i = 0; i < n; i++)
        cin >> num[i];
    cin >> k;

    for(int i = 0; i < n; i++) {

        for(int j = i + 1; j < n; j++) {

            if(num[i] + num[j] == k)
                answer = true;

        }

    }

    cout << answer;

}