#include <iostream>
#include <cmath>

using namespace std;

int nameArray() {

    int index1 = 0;
    int index2 = 0;
    int max = 100;
    char name1[max];
    char name2[max];
    char input1;
    char input2;

    cout << "Enter first name characters one by one. Input '.' to stop." << "\n";

    while (index1 < max) {
        cin >> input1;

        if (input1 == '.') {
            break;
        }

        name1[index1++] = input1;
    }

    cout << "Enter last name characters one by one. Input '.' to stop." << "\n";

    while (index2 < max) {
        cin >> input2;

        if (input2 == '.') {
            break;
        }

        name2[index2++] = input2;
    }

    cout << "First name: ";

    int i = 0;
    for (; i < index1; i++) {
        cout << name1[i];
    }

    cout << "\n";

    cout << "Last name: ";

    for (i = 0; i < index2; i++) {
        cout << name2[i];
    }

    return 0;
}

int factor(int n) {

    int count = 0;
    int X = 1;

    for (; X <= sqrt(n); X++) {
        if (n % X == 0) {
            count += 1;
            cout << X << " ";
        }
    }

    cout << "\n" << "Number of factors: " << count << "\n";

    return 0;
}

int score(int n) {

    float worst, secondWorst, a, b;

    cout << "Enter first two scores." << "\n";
    cout << "-------> ";
    cin >> a >> b;

    if (a > b) {
        worst = b;
        secondWorst = a;
    } else {
        worst = a;
        secondWorst = b;
    }

    for (int i = 3; i <= n; i++) {
        cout << "Enter next score." << "\n";
        cout << "-------> ";
        cin >> a;

        if (a < worst) {
            secondWorst = worst;
            worst = a;
        } else if (a < secondWorst) {
            secondWorst = a;
        }
    }

    cout << "\nWorst score: " << worst << "\n" << "Second-worst score: " << secondWorst << "\n";

    return 0;
}

int numArray(int n) {

    int i = 0;
    int A[n];

    for (; i < n; i++) {
        cout << "Enter number." << "\n";
        cout << "-------> ";
        cin >> A[i];
    }

    int lessThanTen = 0;
    int sum = 0;
    bool E = false;

    for (i = 0; i < n; i++) {
        if (A[i] < 10) {
            lessThanTen += 1;
        }

        if (A[i] == 25) {
            E = true;
        }

        sum += A[i];
    }

    if (E == true) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }

    cout << "Sum of the array: " << sum << "\n" << "Count of numbers less than ten: " << lessThanTen << "\n";

    return 0;
}

double quadEquat(double a, double b, double c) {

    double x;
    double X;
    double g;

    if (a == 0 && b == 0) {
        cout << "This equation has no answer.";
        return 0;
    } else if (a == 0) {
        cout << "x = " << -c / b;
        return 0;
    } else {
        g = b * b - 4 * a * c;

        if (g < 0) {
            cout << "This equation has no answer.";
            return 0;
        } else if (g == 0) {
            cout << "x = " << -b / (2 * a);
            return 0;
        } else {
            x = (-b + sqrt(g)) / (2 * a);
            X = (-b - sqrt(g)) / (2 * a);
            cout << "x = " << x << " , " << X;
            return 0;
        }
    }
}

int main() {

    string confirmation;
    short int question;
    long long studentid;

    cout << "1. Enter your student number." << "\n";
    cout << "-------> ";
    cin >> studentid;

    while (true) {
        cout << "----------------------------------------" << "\n";
        cout << "2. Choose a question." << "\n";
        cout << "\t Q1: List the coefficients of 5 from 5 up to 200" << "\n";
        cout << "\t Q2: Quadratic equation" << "\n";
        cout << "\t Q3: Sum of array, count numbers less than 10 and check for 25" << "\n";
        cout << "\t Q4: A piecewise function" << "\n";
        cout << "\t Q5: Check for prime" << "\n";
        cout << "\t Q6: Triangle area and perimeter" << "\n";
        cout << "\t Q8: Show worst and second-worst scores" << "\n";
        cout << "\t Q10: Show the factors of a number and their count" << "\n";
        cout << "\t Q16: Placing name in an array" << "\n";
        cout << "----------------------------------------" << "\n";
        cout << "-------> ";
        cin >> question;

        switch (question) {
        case 1: {
            int result;
            for (int coefficient = 1; coefficient <= 40; coefficient++) {
                result = coefficient * 5;
                cout << result << "\n";
            }
            cout << "\n";
            break;
        }
        case 2: {
            double a, b, c;
            cout << "ax^2 + bx + c = 0" << "\n";
            cout << "Enter a b c" << "\n";
            cout << "-------> ";
            cin >> a >> b >> c;
            quadEquat(a, b, c);
            cout << "\n";
            break;
        }
        case 3: {
            int n;
            cout << "Enter the length of your array." << "\n";
            cout << "-------> ";
            cin >> n;
            numArray(n);
            cout << "\n";
            break;
        }
        case 4: {
            long long x;
            long long result;
            cout << "f(x) = \n";
            cout << "For (x > 1) ----> x^4 - 2x^2 + 5x - 3\n";
            cout << "For (x = 1) ----> -2\n";
            cout << "For (x < 1) ----> 4x^3 - x(x + 1) - 1\n\n";
            cout << "Enter x:\n";
            cout << "-------> ";
            cin >> x;

            if (x == 1) {
                result = -2;
            } else if (x > 1) {
                result = pow(x, 4) - 2 * pow(x, 2) + 5 * x - 3;
            } else {
                result = 4 * pow(x, 3) - x * (x + 1) - 1;
            }

            cout << "f(" << x << ") = " << result << "\n\n";
            break;
        }
        case 5: {
            long long number;
            cout << "Enter a number:\n";
            cout << "-------> ";
            cin >> number;

            if (number <= 1) {
                cout << "Not prime.\n\n";
            } else if (number == 2) {
                cout << "Prime.\n\n";
            } else if (number % 2 == 0) {
                cout << "Not prime.\n\n";
            } else {
                int i = 3;
                bool prime = true;
                long long limit = sqrt(number);

                while (i <= limit) {
                    int remainder = number % i;
                    if (remainder == 0) {
                        cout << "Not prime.\n\n";
                        prime = false;
                        break;
                    }
                    i = i + 2;
                }

                if (prime) {
                    cout << "Prime.\n\n";
                }
            }
            break;
        }
        case 6: {
            double a, b, c;
            bool realtri = 1;
            cout << "Enter triangle's sides." << "\n";

            while (realtri) {
                cout << "-------> ";
                cin >> a >> b >> c;

                if (a + b > c && a + c > b && b + c > a) {
                    double semiPer = (a + b + c) / 2;
                    double area = sqrt(semiPer * (semiPer - a) * (semiPer - b) * (semiPer - c));
                    cout << "Perimeter: " << semiPer * 2 << "\n";
                    cout << "Area: " << semiPer << "\n";
                    realtri = 0;
                } else {
                    cout << "This is not a real triangle. Enter the sides again." << "\n";
                }
            }
            break;
        }
        case 8: {
            int n;
            cout << "Enter number of scores." << "\n";
            cout << "-------> ";
            cin >> n;
            score(n);
            cout << "\n";
            break;
        }
        case 10: {
            int n;
            cout << "Enter an integer." << "\n";
            cout << "-------> ";
            cin >> n;
            cout << "Its integer factors: ";
            factor(n);
            cout << "\n";
            break;
        }
        case 16: {
            nameArray();
            cout << "\n";
            break;
        }
        default: {
            cout << "Invalid input, try again." << "\n";
            continue;
        }
        }

        bool confirm = true;
        while (confirm) {
            cout << "Do you want to continue? (Y/N)" << "\n";
            cout << "-------> ";
            cin >> confirmation;
            confirm = false;

            if (confirmation == "N" || confirmation == "n") {
                cout << "Quitting..." << "\n";
                return 0;
            } else if (confirmation != "Y" && confirmation != "y") {
                cout << "Invalid input, try again." << "\n";
                confirm = true;
            }
        }
    }

    return 0;
}