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
    cout<<"Enter first name characters one by one. Input '.' to stop."<<"\n"; 
    while (index1 < max) {
        cin>>input1;
        if (input1 == '.') {
            break;
        }
        name1[index1++] = input1;
    }
    cout<<"Enter last name characters one by one. Input '.' to stop."<<"\n"; 
        while (index2 < max) {
        cin>>input2;
        if (input2 == '.') {
            break;
        }
        name2[index2++] = input2;
    }
    cout<<"First name: "; 
        int i = 0;
        for (; i < index1; i++) { 
        cout<<name1[i];
        }
        cout<<"\n";
        cout<<"Last name: ";
        for (i = 0; i < index2; i++) {
        cout<<name2[i];
        }
      return 0;

}

int factor(int n) {
    int count = 0;
    int X = 1;
    for (; X <= sqrt(n); X++) {
        if (n % X == 0) {
            count += 1;
            cout<<X<<" ";
        }
    }
    cout<<"\n"<<"Number of factors: "<<count<<"\n";
    return 0;
}

int score(int n) {
    float worst, secondWorst, a, b;
    cout<<"Enter first two scores."<<"\n";
    cout<<"------> ";
    cin>>a>>b;
    if (a > b) {
        worst = b;
        secondWorst = a;
    } else {
        worst = a;
        secondWorst = b;
    }
    for (int i = 3; i <= n; i++) {
        cout<<"Enter next score."<<"\n";
        cout<<"------> ";
        cin>>a;
        if (a < worst) {
            secondWorst = worst;
            worst = a;
        } else if (a < secondWorst) {
            secondWorst = a;
        }        
    }
    cout<<"\nWorst score: "<<worst<<"\n"<<"Second-worst score: "<<secondWorst<<"\n";
    return 0;
}

int numArray(int n) {
    int i = 0;
    int A[n];
    for (; i < n; i++) {
        cout<<"Enter number."<<"\n";
        cout<<"------> ";
        cin>>A[i];
    }
    int lessThanTen = 0;
    int sum = 0;
    bool E = false;
    for (i = 0;i < n ; i++) {
     if (A[i] < 10) {
        lessThanTen += 1;
     }
     if (A[i] == 25) {
        E = true;
     }
     sum += A[i];
    }
    if (E == true) {
        cout<<"Yes"<<"\n";
    } else {
        cout<<"No"<<"\n";
    }
    cout<<"Sum of the array: "<<sum<<"\n"<<"Count of numbers less than ten: "<<lessThanTen<<"\n";
    return 0;
}

double quadEquat(double a, double b, double c) {
    double x;
    double X;
    double g;
    if (a == 0 && b == 0) {
        cout<<"This equation has no answer.";
        return 0;
    } else if (a == 0) {
        cout<<"x = "<<-c/b;
        return 0;
    } else {
        g = b * b - 4 * a * c;
        if (g < 0) {
            cout<<"This equation has no answer.";
            return 0;
        } else if (g == 0) {
            cout<<"x = "<<-b / (2 * a);
            return 0; 
        } else {
            x = (-b + sqrt(g)) / (2 * a);
            X = (-b - sqrt(g)) / (2 * a);
            cout<<"x = "<<x<<" , "<<X;
            return 0;
        }

    }
}

int main() {
    string confirmation;
    char question;
    long long studentid;
    cout<<"1. Enter your student number."<<"\n";
    cout<<"------> ";
    cin>>studentid;
    while (true) {
        cout<<"----------------------------------------"<<"\n";
        cout<<"2. Choose a question."<<"\n";
        cout<<"\ta. Q1: list the coefficients of 5 from 5 up to 200"<<"\n";
        cout<<"\tb. Q2: Quadratic equation"<<"\n";
        cout<<"\tc. Q3: Sum of array, count numbers less than 10 and check for 25"<<"\n";
        cout<<"\td. Q8: Show worst and second-worst scores"<<"\n";
        cout<<"\te. Q10: Show the factors of a number and their count"<<"\n";
        cout<<"\tf. Placing name in an array"<<"\n";
        cout<<"------> ";
        cin>>question;
        cout<<"----------------------------------------"<<"\n";
        switch (question) {
            case 'a': {
                int result;
                for (int coefficient = 1; coefficient <= 40; coefficient++) {
                    result = coefficient * 5;
                    cout<<result<<"\n";
                }
                cout<<"\n";
                break;
            }
            case 'b': {
                double a, b, c;
                cout<<"ax^2 + bx + c = 0"<<"\n";
                cout<<"Enter a b c"<<"\n";
                cout<<"------> ";
                cin>>a>>b>>c;
                quadEquat(a, b, c);
                cout<<"\n";
                break;
            }
            case 'c': {
                int n;
                cout<<"Enter the length of your array."<<"\n";
                cout<<"------> ";
                cin>>n;
                numArray(n);
                cout<<"\n";
                break;
            }
            case 'd': {
                int n;
                cout<<"Enter number of scores."<<"\n";
                cout<<"------> ";
                cin>>n;
                score(n);
                cout<<"\n";
                break;
            }
            case 'e': {
                int n;
                cout<<"Enter an integer."<<"\n";
                cout<<"------> ";
                cin>>n;
                cout<<"Its integer factors: ";
                factor(n);
                cout<<"\n";
                break;
            }
            case 'f': {
                nameArray();
                cout<<"\n";
                break;
            }
            default: {
                cout<<"Invalid input, try again."<<"\n";
                continue;
            }
        }
        bool confirm = true;
        while (confirm) {
        cout<<"Do you want to continue? (Y/N)"<<"\n";
        cout<<"------> ";
        cin>>confirmation;
        confirm = false;
        if (confirmation == "N" || confirmation == "n") {
            cout<<"Quitting..."<<"\n";
            return 0;
        } else if (confirmation != "Y" && confirmation != "y") {
            cout<<"Invalid input, try again."<<"\n";
            confirm = true;
            continue;
        }
        }
    }
    return 0;
}

