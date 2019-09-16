#include <iostream>
#include <string>

using namespace std;

int main() {

    bool match = true;
    int answer = 0;
    string output, input;
    cin >> input;
    cin >> output;
    int i[output.length() + 1], max[output.length() + 1];
    for(int j = 0; j < output.length() + 1; j++)
        i[j] = 0;
    for(int k = 0; k < output.length() + 1; k++)
        max[k] = input.length() - output.length() + 1 + k;
    int p = 0;

    while(i[output.length()] == 0) {

        match = true;

        for(int a = 0; a < output.length(); a++) {

            if(output.at(a) != i[a])
                match = false;

        }

        if(match)
            answer++;

        i[0]++;

        while(i[p] = max[p]) {

            i[p] = 0;
            p++;
            i[p]++;
            if(i[p] != max[p])
                p = 0;

        }

    }

    cout << answer;

}