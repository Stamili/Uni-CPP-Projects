#include <iostream>
#include <math.h>

using namespace std;

void show_integrated_function(double coe[],short int arrayLen, double deg);

int main() {
    short int a, b, i;
    double deg;
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
    short int arrayLen = deg + 1;
    double coe[arrayLen];
    
    for (i = 0; i < arrayLen; i++) {
        if (deg - i != 0) 
        cout << "Enter the coefficient for " << "x^" << deg - i << ": ";
        else 
        cout << "Enter the constant: ";
        cin >> coe[i];
        if (coe [0] == 0) {
        cout << "First term can't have 0 as coefficient." << "\n";
        i = -1;
        }
    }
    cout << "\n" << "f(x) = ";
    bool firstTerm = true;
    for (i = 0; i < arrayLen; i++) {
    if (coe[i] == 0) {
        continue;
    } else {
        if (!firstTerm && coe[i] > 0) {
            cout << " + ";
        }
        if (coe[i] < 0) {
            cout << " - ";
        }
        if (coe[i] != 1 || (coe[i] == 1 && (deg - i == 0))) {
            if (coe[i] > 0)
            cout << coe[i];
            if (coe[i] < 0)
            cout << -coe[i];
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
}   cout << "\n";
    show_integrated_function(coe, arrayLen, deg);
    cout << "\n\n";

}

void show_integrated_function(double coe[],short int arrayLen, double deg) {
    deg++;
    for (int i = 0; i < arrayLen; i++) {
        if (coe[i] != 0)
        coe[i] *= 1 / (deg - i);  
    }
    
    cout << "\n" << "F(x) = ";
    bool firstTerm = true;
    for (int i = 0; i < arrayLen; i++) {
    if (coe[i] == 0) {
        continue;
    } else {
        if (!firstTerm && coe[i] > 0) {
            cout << " + ";
        }
        if (coe[i] < 0) {
            cout << " - ";
        }
        if (coe[i] != 1 || (coe[i] == 1 && (deg - i == 0))) {
            if (coe[i] > 0)
            cout << coe[i];
            if (coe[i] < 0)
            cout << -coe[i];
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
cout << " + C";
}
