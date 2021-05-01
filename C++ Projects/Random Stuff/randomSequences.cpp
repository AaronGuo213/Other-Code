#include <iostream>
using namespace std;

int main() {

    int cycles = 9;
    int numOptions = 12;
    char options[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b'};
    bool isUsed[numOptions];
    int choice;

    for(int i = 0; i < cycles; i++) {
        for(int j = 0; j < numOptions; j++) {
            isUsed[j] = false;
        }
        for(int j = 0; j < numOptions; j++) {
            choice = rand() % numOptions;
            while(isUsed[choice]) {
                choice = rand() % numOptions;
            }
            cout << options[choice];
            isUsed[choice] = true;
        }
    }

}