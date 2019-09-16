#include <iostream>
using namespace std;

const int n = 3;
const int k = 3;
int cheapestDistinctHouses(int price[n][k]) {

    int cheapest, runnerUp, prevColor = -1, holder;
    int a, b;
    for(int i = 0; i < n; i++) {
        a, b = 1000000, 1000000;
        for(int j = 0; j < k; j++) {
            holder = prevColor;
            if(price[i][j] <= a && j != prevColor) {
                b = a;
                a = price[i][j];
                prevColor = i;
            }
            else if(price[i][j] <= b && j != prevColor) {
                b = price[i][j];
            }
        }
        runnerUp = cheapest + b;
        cheapest += a;
        if(i > 0 && runnerUp + price[i][holder] <= cheapest) {
            runnerUp = cheapest;
            cheapest = runnerUp + price[i][holder];
            prevColor = holder;
        }
    }
    return cheapest;

}