#include <iostream>
using namespace std;

/*int findDecimal(int divisor, int place) {

    int remainder = 1;
    for(int i = 0; i < place - 1; i++) {
        remainder = (remainder * 10) % divisor;
        if(remainder == 0)
            return -1;
    }
    return remainder * 10 / divisor;

}

int repeatLength(int divisor) {

    bool pairFound = false;
    int maxDisp = 1000, currentDisp = 0, count = 10;
    for(int i = 1; i < maxDisp; i++) {
        
        pairFound = false;
        for(int j = i + 1; !pairFound && j < maxDisp; j++) {

            if(findDecimal(divisor, j) == -1)
                return 0;

            if(findDecimal(divisor, j) == findDecimal(divisor, i)) {
                pairFound = true;
                if(j - i != currentDisp) {
                    currentDisp = j - i;
                    count = currentDisp - 1;
                }
                else
                    count --;
                
                if(count == 0)
                    return currentDisp;
            }

        }

    }

    return 0;

}

int main() {

    int longestRepeat = 0, id;
    for(int i = 1; i < 1000; i++) {
        if(repeatLength(i) > longestRepeat) {
            longestRepeat = repeatLength(i);
            id = i;
        }
    }

    cout << "The reciprocal of " << id << " has the longest repeating string of every reciprocal of a number below 1000, with a length of " << longestRepeat << ".\n";

}*/

int main() {

int sequenceLength = 0, num;
 
for (int i = 1000; i > 1; i--) {
    if (sequenceLength >= i) {
        break;
    }
 
    int foundRemainders[i];
    for(int j = 0; j < i; j++)
        foundRemainders[j] = 0;
    int value = 1;
    int position = 0;
 
    while (foundRemainders[value] == 0 && value != 0) {
        foundRemainders[value] = position;
        value *= 10;
        value %= i;
        position++;
    }
 
    if (position - foundRemainders[value] > sequenceLength) {
        sequenceLength = position - foundRemainders[value];
        num = i;
    }
}

    cout << "The number with the longest recurring cycle is " << num << ", and the cycle is length is " << sequenceLength << ".\n";

}