#include <iostream>
using namespace std;

int numPaths(int n, int m) {

    int answer = 0;
    if(n > 1)
        answer += numPaths(n - 1, m);
    else
        return 1;
    if(m > 1)
        answer += numPaths(n, m - 1);
    else 
        return 1;

    return answer;

}

int main() {

    int answer = numPaths(10, 10);
    cout << answer;

}