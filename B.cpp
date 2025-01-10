#include <iostream>
#include <math.h>

using namespace std;


int main() {
    short int a, b, deg, i;
    cout << "Integration of f(x) over the interval [a,b]." << "\n\n";
    /* cout << "Enter a and b, should be between -1 and 5: ";
    while (true) {
        cin >> a >> b;
        if (a <= 5 && a >= -1 && b <= 5 && b >= -1) {
            break;
        } else {
            cout << "Invalid input, try again." << "\n";
        }
    } */
    cout << "Enter the degree of the polynomial function f(x): ";
    cin >> deg;
    double coe[deg + 1];
    for (i = 0; i < deg + 1; i++) {
        cout << "Enter coefficient for " << "x^" << deg - i << ": ";
        cin >> coe[i];
    }
    cout << "f(x) = ";
    bool firstTerm = true;
    for (i = 0; i < deg + 1; i++) {
    if (coe[i] == 0) {
        continue;
    } else {
        if (!firstTerm && coe[i] > 0) {
            cout << " + ";
        }
        if (coe[i] < 0) {
            cout << " - ";
            coe[i] = -coe[i];
        }
        if (coe[i] != 1 || (coe[i] == 1 && (deg - i == 0))) {
            cout << coe[i];
        }
        if (deg - i != 0) {
            if (deg - i == 1) {
                cout << "x";
            } else {
                cout << "x^" << deg - i;
            }
        }
        firstTerm = false;
    }
}
cout << "\n\n";

}