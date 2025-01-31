#include <iostream>
#include <cmath>

using namespace std;

double calculate_power(double a, double b) {
    double result = 1;
    if (b == 0 || a == 1)
    return 1;
    else if (a == 0 || b == 1)
    return a;
    else if (b < 0) {
        a = 1/a;
        for (int i = -b; i != 0; i--) {
            result *= a;
        } 
        return result;
    } else {
        for (int i = 0; i != b; i++) {
            result *= a;
        }
        return result;
    }
}

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

int numArray(int arrayLen) {

    int i = 0;
    int A[arrayLen];

    for (; i < arrayLen; i++) {
        cout << "Enter number." << "\n";
        cout << "-------> ";
        cin >> A[i];
    }

    int lessThanTen = 0;
    int sum = 0;
    bool E = false;

    for (i = 0; i < arrayLen; i++) {
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

    double x1;
    double x2;
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
            x1 = (-b + sqrt(g)) / (2 * a);
            x2 = (-b - sqrt(g)) / (2 * a);
            cout << "x = " << x1 << " , " << x2;
            return 0;
        }
    }
}

int main() {
    string confirmation;
    short int question;
    /* long long studentID;
    bool validID = false;
    cout << "1) Enter your student number." << "\n";
    while (!validID) {
    cout << "-------> ";
    cin >> studentID;
    if (studentID >= 1000000000 && studentID <= 9999999999)  {
        validID = true;
    } else {
        cout << "Invalid ID, try again." << "\n";
    }
    } */
    
    while (true) {
        cout << "----------------------------------------" << "\n";
        cout << "2) Choose a question." << "\n\n";
        cout << "1.  List the coefficients of 5 from 5 up to 200" << "\n";
        cout << "2.  Quadratic equation" << "\n";
        cout << "3.  Sum of array, count numbers less than 10 and check for 25" << "\n";
        cout << "4.  A piecewise function" << "\n";
        cout << "5.  Check for prime" << "\n";
        cout << "6.  Triangle area and perimeter" << "\n";
        cout << "7.  Fibonacci sequence" << "\n";
        cout << "8.  Show worst and second-worst scores" << "\n";
        cout << "9.  Number of digits" << "\n";
        cout << "10. Show the factors of a number and their count" << "\n";
        cout << "12. Power function" << "\n";
        cout << "13. Show the next three even numbers" << "\n";
        cout << "14. Result of a sequence up to a certain term" << "\n";
        cout << "16. Placing name in an array" << "\n";
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
            int arrayLen;
            cout << "Enter the length of your array." << "\n";
            cout << "-------> ";
            cin >> arrayLen;
            numArray(arrayLen);
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
            bool realTri = 1;
            cout << "Enter triangle's sides." << "\n";

            while (realTri) {
                cout << "-------> ";
                cin >> a >> b >> c;

                if (a + b > c && a + c > b && b + c > a) {
                    double semiPer = (a + b + c) / 2;
                    double area = sqrt(semiPer * (semiPer - a) * (semiPer - b) * (semiPer - c));
                    cout << "Perimeter: " << semiPer * 2 << "\n";
                    cout << "Area: " << area << "\n";
                    realTri = 0;
                } else {
                    cout << "This is not a real triangle. Enter the sides again." << "\n";
                }
            }
            break;
        }
        case 7: {
            long long elementNum;
            long long resultNum = 1;
            long long prevNum = 0;
            long long temp;
            bool invalidElement = true;
            cout << "Enter the element number to show. (From zero)" << "\n";

            while (invalidElement) {
            cout << "-------> ";
            cin >> elementNum;
            invalidElement = false;
            if (elementNum <= -1) {
                cout << "Invalid input, try again." << "\n";
                invalidElement = true;
                continue;
            } else if (elementNum == 0) {
                cout << "F(0): " << prevNum << "\n\n";
            } else {
            long long i;
            for (i = 1; i < elementNum; i++) {
                temp = resultNum;
                resultNum = prevNum + resultNum;
                prevNum = temp;
            }
            
            cout << "F(" << elementNum << "): " << resultNum << "\n\n";
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
        case 9: {
            long long num;
            short int digitCount;
            cout << "Enter number." << "\n";
            cout << "-------> ";
            cin >> num;

            for (digitCount = 0; num != 0; digitCount++) {
                num /= 10;
            }
            if (digitCount == 0 || digitCount == 1) {
                cout << "1 digit" << "\n\n";
            } else {
                cout << digitCount << " digits" << "\n\n";
            }
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
        case 12: {
            double a, b;
            cout << "a^b" << "\n" << "Enter a and b: ";
            cin >> a >> b;
            cout << "\n" << a << "^" << b << " = "<< calculate_power(a, b) << "\n\n";
            break;
        }
        case 13: {
            double number;
            cout << "Enter number: ";
            cin >> number;
            if (number != floor(number))
            number = ceil(number);
            if (fmod(number, 2) == 0)
            cout << "\n" << number + 2 << "\t" << number + 4 <<
            "\t" << number + 6 << "\n\n";
            else
            cout << "\n" << number + 1 << "\t" << number + 3 <<
            "\t" << number + 5 << "\n\n";
            break;
        }
        case 14: {
            long long termNum, i, j;
            long long result = 0;
            cout << "S = 1^2 - 2^3 + 3^4 - 4^5 ..." << "\n";
            cout << "Enter the term number to stop the calculation at: ";
            bool validTerm = false;
            while (!validTerm) {
            cin >> termNum;
            if (termNum <= 0 || termNum != floor(termNum)) {
                cout << "\n" << "Invalid input, try again. ";
            } else {
                validTerm = true;
            }
            }
            j = 2;
            for (i = 1; i != termNum + 1; i++) {
                    if (i % 2 == 0)
                    result -= pow(i, j);
                    else
                    result += pow(i, j);
                    j++;
            }
            cout << "\n" << "Result: " << result << "\n\n";
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