#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int number;
    int factor = 2;
    int quotient;

    cout << "What is the number?" << endl;
    cin >> number;

    cout << "The largest prime factor of " << number << " is ";
    
    while (number == !1){
    	if (number % factor == 0){
    		number = number / factor;
    		if (number == !1)
				factor = 2;
		}
		else
		factor = factor + 1;
	}
	
	cout << factor << "." << endl;
	return 0;}
