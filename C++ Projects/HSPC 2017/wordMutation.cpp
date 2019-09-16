/*Given a list of words, determine whether there exists an
mutation order of the words, such that for every word in the list,
the next word can be made by changing only 1 letter in the 
word. Return 1 if such an order exists, otherwise return 0.*/

#include <iostream>
#include <string>

using namespace std;

int main() {

    bool answer = true, check = false;
    int n, diff = 0;
    cin >> n;
    string str[n];

    for(int i = 0; i < n; i++)
        cin >> str[i];

    for(int i = 0; i < n; i++) {

        for(int j = 0; j < n; j++) {

            if(i != j) {

                for(int k = 0; k < str[0].length(); k++) {

                    if(str[i].at(k) != str[j].at(k))
                        diff++;

                }

            }

            if(diff == 1)
                check = true;

            diff = 0;

        }

        if(!check)
            answer = false;

        check = false;

    }

    cout << answer;

}