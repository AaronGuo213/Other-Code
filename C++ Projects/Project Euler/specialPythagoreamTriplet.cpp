#include <iostream>
#include <cmath>
using namespace std;

int main() {

    int a, b, target = 1000;
    for(a = 1; a < 500; a++) {
        for(b = a + 1; b < 500; b++) {
            if(a + b + sqrt(a * a + b * b) == target)
                break;
        }
        if(a + b + sqrt(a * a + b * b) == target)
            break;
    }
    cout << "The pythagorean triple that sums to " << target << " is " << a << ", " << b <<", and " << sqrt(a * a + b * b) << ".\n";
    return 0;

}