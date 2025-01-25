#include <iostream>
#include <math.h>

using namespace std;

void show_function(double coe[], short int arrayLen, double deg);
double integral_result(double coe[], short int arrayLen, double deg, double a, double b);

int main() {
    short int i;
    double deg, a, b;
    char again;
    bool redo = true;
    while (redo) {
    cout << "Integration of f(x) over the interval [a,b]." << "\n\n";
    cout << "Enter a and b, should be between -1 and 5: ";
    while (true) {
        cin >> a >> b;
        if (a <= 5 && a >= -1 && b <= 5 && b >= -1) {
            break;
        } else {
            cout << "Invalid input, try again." << "\n";
        }
    }
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
    show_function(coe, arrayLen, deg);

    deg++;
    for (int i = 0; i < arrayLen; i++) {
        if (coe[i] != 0)
        coe[i] *= 1 / (deg - i);  
    }
    
    cout << "\n\n" << "F(x) = ";
    show_function(coe, arrayLen, deg);
    
    cout << " + C";
    cout << "\n\n";
    cout << "Result of F(x) over the interval [" << a << "," << b << "]: "<< integral_result(coe, arrayLen, deg, a, b) << "\n\n";
    cout << "\n" << "Would you like to do another one? (Y/N) ";
    while (1) {
    cin >> again;
    if (again == 'N' || again == 'n') {
    redo = false;
    break;
    } else if (again != 'Y' && again != 'y') {
        cout << "Invalid input. Try again. ";
    } else {
        cout << "\n";
        break;
    }
}
}
}

double integral_result(double coe[], short int arrayLen, double deg, double a, double b) {
    int i;
    double lowerLimitResult;
    double upperLimitResult;
    double finalResult;
    double temp = 0;
    for (i = 0; i < arrayLen; i++) {
        lowerLimitResult = coe[i] * pow(a, deg - i);
        temp += lowerLimitResult;
    }
    lowerLimitResult = temp;
    temp = 0;
    for (i = 0; i < arrayLen; i++) {
        upperLimitResult = coe[i] * pow(b, deg - i);
        temp += upperLimitResult;
    }
    upperLimitResult = temp;
    finalResult = upperLimitResult - lowerLimitResult;
   
    return finalResult;
}

void show_function(double coe[], short int arrayLen, double deg) {
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
}
