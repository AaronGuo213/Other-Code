/*Often, we hear commercials give out their numbers with phrases.
When we press for the phrases on the keypad, we are indirectly
translating the phrases into numbers. Now, we want to know
what are the actual numbers based on a typical keypad
configuration*/

#include <iostream>
#include <string>

using namespace std;

int main() {

    string input, output;
    char victim;
    int ascii;
    cin >> input;

    for(int i = 0; i < input.length(); i++) {

        victim = input.at(i);
        if(int(victim) > 64 && int(victim) < 91)
            ascii = int(victim) + 32;
        else
            ascii = int(victim);

        if(ascii > 96 && ascii < 100)
            victim = '2';
        if(ascii > 99 && ascii < 103)
            victim = '3';
        if(ascii > 102 && ascii < 106)
            victim = '4';
        if(ascii > 105 && ascii < 109)
            victim = '5';
        if(ascii > 108 && ascii < 112)
            victim = '6';
        if(ascii > 111 && ascii < 116)
            victim = '7';
        if(ascii > 115 && ascii < 119)
            victim = '8';
        if(ascii > 118 && ascii < 123)
            victim = '9';

        output += victim;

    }

    cout << output;

}