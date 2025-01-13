#include <iostream>
#include <cstring>

using namespace std;

int main() {
    short int textLength = 501;
    short int i;
    short int digitSum = 0;
    long long numberSum = 0;
    short int charCount = 0;
    short int customCharCount = 0;
    char customChar;
    char countQuestion;
    short int wordCount = 0;
    char text[textLength];
    cin.get(text,textLength);
    
    //Digit summation.
    for (i = 0; text[i] != '\0'; i++) { 
        if (text[i] >= '1' && text[i] <= '9')
        digitSum += text[i] - '0';
    }
    cout << "\n" << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n" << "Sum of the digits: " << digitSum << "\n";

    //Character count.
    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] == ' ')
        continue;
        charCount++;
    }
    cout <<"Character count: " << charCount << "\n";
    
    //Word count.
    for (i = 0; text[i] != '\0'; i++) {
         if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z')) {
            while (text[i] != ' ') {
                i++;
            }
        wordCount++;
        }
    }
    cout << "Word count: " << wordCount << "\n";
    
    //Number summation.
    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] >= '1' && text[i] <= '9') {
            short int j = 0;
            char temp[textLength];
            while (text[i] >= '0' && text[i] <= '9') {
                temp[j] = text[i];
                i++;
                j++;
            }
            temp[j] = '\0';
            numberSum += atoi(temp);
        }
    }
    cout << "Sum of the numbers: " << numberSum << "\n";
    
    //Custom character count
    bool ask;
    while (true) {
    cout << "Would you like to count a character? (y/n) ";
    cin >> countQuestion;
    if (countQuestion == 'y' || countQuestion == 'Y') {
        ask = true;
        break;
    }
    else if (countQuestion != 'n' && countQuestion != 'N') {
        cout << "Invalid input. Try again." << "\n";
    } else if (countQuestion == 'n' || countQuestion == 'N') {
        ask = false;
        break;
    }
    }
    while (ask) {
    cout << "Which character would you like to count? ";
    cin >> customChar;
    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] == customChar)
        customCharCount++;
    }
    cout << "\n" << "'" << customChar << "'" << " count: " << customCharCount << "\n";
    customCharCount = 0;
    bool invalidInput = true;
    while (invalidInput) {
    cout << "Would you like to count another character? (y/n) ";
    cin >> countQuestion;
    invalidInput = false;
    if (countQuestion == 'N' || countQuestion == 'n') {
        ask = false;
        break;
    }
    else if (countQuestion != 'y' && countQuestion != 'Y') {
        cout << "Invalid input. Try again." << "\n";
        invalidInput = true;
    } 
    }  
    }
}