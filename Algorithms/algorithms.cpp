#include <iostream>
#include <map>
#include <vector>
#include <set>
#include "chapter1.h"

using namespace std;


void selectMenu() {

    int index = -1;

    cout << "\n==================================" << endl;
    cout << "Select Function Index:" << endl;
    cout << "0. Exit" << endl;
    cout << "1. Greatest Common Divisor" << endl;
    cout << "2. SQRT" << endl;
    cout << "==================================\n" << endl;
    
    cin >> index;
    switch (index) {
        case 0: {
            cout << "See you~" << endl;
            return;
        }
        case 1: {
        	cout << "Please Input First Integer:" << endl;
        	int a;
        	cin >> a;
        	
        	cout << "Please Input Second Integer:" << endl;
        	int b;
        	cin >> b;
        	if (a > 0 && b > 0)
        	{
        		cout << "The Greatest Common Divisor of " << a << " and " << b << " is " << gcd(a, b);

        	} else {
        		cout << "Error: Input Wrong Value." << endl;
        	}
        	break;

        }
        case 2: {
        	cout << "Please Input a Number:" << endl;
        	int a;
        	cin >> a;
        	cout << "sqrt(" << a << ") = " << ny_sqrt(a);
        	break;
        }
        default: {
            cout << "===== Not Found Selected Index =====\n" << endl;
            break;
        }

    }

    selectMenu();

}

int main() {
	cout << "Hello" << endl;
	selectMenu();
	return 0;
}