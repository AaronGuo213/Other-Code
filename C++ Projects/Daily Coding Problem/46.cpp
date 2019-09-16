#include <iostream>
#include <string>
using namespace std;

int main() {

    string word = "aabcdcb";
    string reverse = "";   
    for(int i = word.length() - 1; i >= 0; i--)
        reverse += word.at(i);
    
    string palindrome, challenger;
    for(int i = word.length() - 1; i >= 0; i--) {
        palindrome = challenger = "";
        for(int j = 0; j + i < word.length(); j++) {
            if(word.at(j) == reverse.at(i + j)) {
                challenger += word.at(j);
            }
            else {
                if(challenger.length() >= palindrome.length())
                    palindrome = challenger;
                challenger = "";
            }
        }
        if(challenger.length() >= palindrome.length())
            palindrome = challenger;
    }

    for(int i = 1; i < word.length(); i++) {
        challenger = "";
        for(int j = 0; j + i < word.length(); j++) {
            if(word.at(i + j) == reverse.at(j))
                challenger += reverse.at(j);
            else {
                if(challenger.length() >= palindrome.length())
                    palindrome = challenger;
                challenger = "";
            }
        }
        if(challenger.length() >= palindrome.length())
            palindrome = challenger;
    }

    cout << palindrome;

}