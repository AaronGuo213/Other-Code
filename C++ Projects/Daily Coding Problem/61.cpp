#include <iostream>
using namespace std;

long pow(int x, int y) {//returns x^y

    if(!y)
        return 1;

    if(y < 0)
        return 1 / pow(x, -y);

    if(y == 1 || !x)
        return x;

    else if(!(y % 2))
        return pow(x * x, y / 2);

    else
        return x * pow(x * x, (y - 1) / 2);

}

int main() {

    cout << pow(3, 10) << endl;

}