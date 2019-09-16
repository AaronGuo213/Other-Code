#include <iostream>
#include <fstream>
using namespace std;

bool isTriangular(string word) {

    int sum = 0;
    for(int i = 0; i < word.length(); i++) {
        sum += int(word.at(i)) - 64;
    }

    int a = 2, triNum = 1;
    while(triNum < sum) {
        triNum += a;
        a ++;
    }
    if(triNum == sum)
        return true;
    return false;

}

int readInput(string text, string words[]) {

    string word = "";
    int count = 0;
    for(int i = 1; i < text.length(); i++) {

        if(text.at(i) == '"') {
            words[count] = word;
            count ++;
            word = "";
            i += 2;
        }

        else {
            word += text.at(i);
        }

    }

    return ++count;

}

int main() {

    ifstream file;
    file.open("p042_words.txt");
    string text;
    file >> text;
    string words[2000] = {};
    int numWords = readInput(text, words);
    int count = 0;
    for(int i = 0; i < numWords; i++) {
        count += isTriangular(words[i]);
    }
    cout << "The number of words in the text file that are coded triangular numbers is " << count << ".\n";

}   