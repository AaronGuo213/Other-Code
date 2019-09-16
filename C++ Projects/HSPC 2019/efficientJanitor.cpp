/*The janitor at Hacker High School is insanely efficient. By the end of
each day, all of the waste from the trash cans in the school has been
shifted into plastic bags which can carry waste weighing between 1.01
pounds and 3.00 pounds. All of the plastic bags must be dumped into
the trash cans outside the school. The janitor can carry at most 3.00
pounds at once. One trip is described as selecting a few bags which
together don't weigh more than 3.00 pounds, dumping them in the
outdoor trash can and returning to the school. The janitor wants to
make minimum number of trips to the outdoor trash can. Given the
number of plastic bags, n, and the weights of each bag, determine the
minimum number of trips if the janitor selects bags in the optimal way.*/

#include <iostream>

using namespace std;

int main() {

    int n, x, y, trips = 0;
    cin >> n;
    float bag[n];
    float optimal = 0;
    for(int i = 0; i < n; i++)
        cin >> bag[i];
    
    for(int a = 0; a < n; a++) {
    
    for(int i = 0; i < n - 1; i++) {

        for(int j = i + 1; j < n; j++) {

            if(bag[i] + bag[j] > optimal && bag[i] + bag[j] < 3.01) {
                optimal = bag[i] + bag[j];
                x = i;
                y = j;
            }

        }

    }

    trips += 1;
    if(bag[x] == 0 && bag[y] == 0) {
        trips--;
    }
    bag[x] = 0;
    bag[y] = 0;
    optimal = 0;

    }

    cout << trips;

}