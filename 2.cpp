#include <iostream>
#include <cmath>
using namespace std;

// This program takes a number and checks for two consecutive, same digits.
// If it's present, it will take the sum of the digits and check whether it's prime or not.
// Then returns both evaluations.
// However, if it does not have two consecutive, same digits, then it will reverse the number and check if the result's prime.
// Then returns both evaluations.

int isPrime(long long n) {
    if (n == 1) {
        cout<<n<<" is not prime";
        return 0;
    }
    if (n == 2) {
        cout<<n<<" is prime";
        return 0;
    }
    for (int i = 3; i <= sqrt(n); i++) {
        if (n % i == 0) {
            cout<<n<<" is not prime";
        } else {
            cout<<n<<" is prime";
        }
        return 0;
    }    
}

int main() {
    long long n;
    short int a;
    short int b = -1;
    bool sameNum = false;
    cout<<"Enter a number: ";
    cin>>n;
    long long c = n;
    while (c != 0) {
        a = c % 10;
        if (a == b) {
            sameNum = true;
        }
        b = a;
        c /= 10;
    }
    if (sameNum == true) {
        c = 0;
        while (n != 0) {
        a = n % 10;
        n /= 10;
        b = n % 10;
        n /= 10;
        c += a + b;  
        }
        cout<<"Sum: "<<c<<endl;
        isPrime(c);      
    } else {
        c = 0;
        short int digit;
        while (n != 0) {
            digit = n % 10;
            c = c * 10 + digit;
            n /= 10;
        }
        cout<<"Reversed: "<<c<<endl;
        isPrime(c);        
    }
    return 0;
}
