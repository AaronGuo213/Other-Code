#include <iostream>

using namespace std;

int main() {

    int n;
    cin >> n;
    int input[n], product[n];
    for(int i = 0; i < n; i++)
        cin >> input[i];

    for(int i = 0; i < n; i++)
        product[i] = 1;
    
    for(int i = 0; i < n; i++) {

        for(int j = 0; j < n; j++) {

            if(j != i)
                product[i] *= input[j];

        }

    }

    cout << "{";
    for(int i = 0; i < n - 1; i++)
        cout << product[i] << ", ";
    cout << product[n - 1] << "}";

}