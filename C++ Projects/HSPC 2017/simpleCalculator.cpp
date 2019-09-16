/*Create a calculator which parses a given String expression which
can have pluses (+), minuses (-), and an equals sign (=) at the
end of the string.*/

#include <iostream>
#include <string>

using namespace std;

int main() {

    string input;
    cin >> input;
    bool negative = 0;
    int n[input.length() / 2];
    int sum = 0;
    for(int i = 0; i < input.length() - 1; i++) {

        if(i % 2 == 0) {
            if(!negative)
                sum += input.at(i) - 48;
            else    
                sum -= input.at(i) - 48;
        }

        else if(i % 2 == 1) {
            if(int(input.at(i)) == 43)
                negative = 0;
            else if(int(input.at(i)) == 45)
                negative = 1;
        }

    }

    cout << sum;

}