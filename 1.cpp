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
    cout<<"Enter first name characters one by one. Input '.' to stop."<<endl; 
    while (index1 < max) {
        cin>>input1;
        if (input1 == '.') {
            break;
        }
        name1[index1++] = input1;
    }
    cout<<"Enter last name characters one by one. Input '.' to stop."<<endl; 
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
        cout<<endl;
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
    cout<<endl<<"Number of factors: "<<count<<endl;
    return 0;
}

int score(int n) {
    float worst, secondWorst, a, b;
    cout<<"Enter first two scores."<<endl;
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
        cout<<"Enter next score."<<endl;
        cout<<"------> ";
        cin>>a;
        if (a < worst) {
            secondWorst = worst;
            worst = a;
        } else if (a < secondWorst) {
            secondWorst = a;
        }        
    }
    cout<<"\nWorst score: "<<worst<<endl<<"Second-worst score: "<<secondWorst<<endl;
    return 0;
}

int numArray(int n) {
    int i = 0;
    int A[n];
    for (; i < n; i++) {
        cout<<"Enter number."<<endl;
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
        cout<<"Yes"<<endl;
    } else {
        cout<<"No"<<endl;
    }
    cout<<"Sum of the array: "<<sum<<endl<<"Count of numbers less than ten: "<<lessThanTen<<endl;
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
    cout<<"1. Enter your student number."<<endl;
    cout<<"------> ";
    cin>>studentid;
    while (true) {
        cout<<"----------------------------------------"<<endl;
        cout<<"2. Choose a question."<<endl;
        cout<<"\ta. Q2: Quadratic equation"<<endl;
        cout<<"\tb. Q3: Sum of array, count numbers less than 10 and check for 25"<<endl;
        cout<<"\tc. Q8: Show worst and second-worst scores"<<endl;
        cout<<"\td. Q10: Show the factors of a number and their count"<<endl;
        cout<<"\te. Placing name in an array"<<endl;
        cout<<"------> ";
        cin>>question;
        cout<<"----------------------------------------"<<endl;
        switch (question) {
            case 'a': {
                double a, b, c;
                cout<<"ax^2 + bx + c = 0"<<endl;
                cout<<"Enter a b c"<<endl;
                cout<<"------> ";
                cin>>a>>b>>c;
                quadEquat(a, b, c);
                cout<<endl;
                break;
            }
            case 'b': {
                int n;
                cout<<"Enter the length of your array."<<endl;
                cout<<"------> ";
                cin>>n;
                numArray(n);
                cout<<endl;
                break;
            }
            case 'c': {
                int n;
                cout<<"Enter number of scores."<<endl;
                cout<<"------> ";
                cin>>n;
                score(n);
                cout<<endl;
                break;
            }
            case 'd': {
                int n;
                cout<<"Enter an integer."<<endl;
                cout<<"------> ";
                cin>>n;
                cout<<"Its integer factors: ";
                factor(n);
                cout<<endl;
                break;
            }
            case 'e': {
                nameArray();
                cout<<endl;
                break;
            }
            default: {
                cout<<"Invalid input, try again."<<endl;
                continue;
            }
        }
        bool confirm = true;
        while (confirm) {
        cout<<"Do you want to continue? (Y/N)"<<endl;
        cout<<"------> ";
        cin>>confirmation;
        confirm = false;
        if (confirmation == "N" || confirmation == "n") {
            cout<<"Quitting..."<<endl;
            exit(0);
        } else if (confirmation != "Y" && confirmation != "y") {
            cout<<"Invalid input, try again."<<endl;
            confirm = true;
            continue;
        }
        }
    }
    return 0;
}

