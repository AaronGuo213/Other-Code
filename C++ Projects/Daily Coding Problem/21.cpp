#include <iostream>
using namespace std;

int minRooms(int time[][2], int numClasses) {

    int count, maxCount = 0;
    for(int i = 0; i < numClasses; i++) {
        count = 0;
        for(int j = 0; j < numClasses; j++) {
            if(j != i) {
                if(time[i][0] <= time[j][0] && time[i][1] > time[j][0])
                    count ++;
                else if(time[i][0] >= time[j][0] && time[i][0] < time[j][1])
                    count ++;
            }
        }
        if(count > maxCount)
            maxCount = count;
    }
    return maxCount;

}

int main() {

    int times[][2] = {{30, 75}, {0, 50}, {60, 150}};
    int numClasses = sizeof(times) / (sizeof(times[0][0]) * 2);
    cout << "The minimum number of rooms is " << minRooms(times, numClasses) << ".\n";

}