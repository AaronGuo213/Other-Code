#include <iostream>
#include <string>
using namespace std;

int fixParenthesis(string str) { //returns the number of parenthesis that must be removed
                                 //to make sure every open-parenthesis is closed

    int unfinishedPar = 0; //keeps track of how many pairs of parenthesis have not been closed
    int removePar = 0; //variable returned for number of parenthesis to be removed
    for(int i = 0; i < str.length(); i++) { //run through every char in the string

        if(str.at(i) == '(')
            unfinishedPar ++; //adds an unclosed pair

        else if(str.at(i) == ')' && unfinishedPar > 0) //if there is still an unfinished pair
            unfinishedPar --; //close that pair, remove one unfinished pair

        else
            removePar ++; //if all pairs before have been closed, the close-parenthesis must be removed

    }

    removePar += unfinishedPar; //add the number of open-parenthesis that haven't been closed yet
    return removePar;

}

int main() {

    string parenthesis = "))(())((())))(()";
    cout << fixParenthesis(parenthesis);

}