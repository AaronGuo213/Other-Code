#include <iostream>
#include <string>
using namespace std;

int main() {

    string name;
    int arr[4] = {0, 0, 0, 0};
    for(int i = 0; i < 59; i++) {
        cin >> name;
        if(name == "aaron")
            arr[0] ++;
        if(name == "tyler")
            arr[1] ++;
        if(name == "noah")
            arr[2] ++;
        if(name == "dom")
            arr[3] ++;
    }

    cout << "aaron: " << arr[0] << " | tyler: " << arr[1] << " | noah: " << arr[2] << " | dom: " << arr[3] << endl;

}