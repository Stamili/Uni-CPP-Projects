#include <iostream>
#include <cstring>

using namespace std;

const short int textLength = 501;
short int i, j;
short int digitSum = 0;
long long numberSum = 0;
short int charCount = 0;
short int customCharCount = 0;
char customChar;
char countQuestion;
short int wordCount = 0;
char text[textLength];

void textInfo() {
    // Digit summation.
    for (i = 0; text[i] != '\0'; i++) { 
        if (text[i] >= '1' && text[i] <= '9')
        digitSum += text[i] - '0';
    }
    cout << "\n" << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n" << "Sum of the digits: " << digitSum << "\n";
    digitSum = 0;

    // Character count.
    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] == ' ')
        continue;
        charCount++;
    }
    cout <<"Character count: " << charCount << "\n";
    charCount = 0;
    
    // Word count.
    for (i = 0; text[i] != '\0'; i++) {
         if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z')) {
            while (text[i] != ' ') {
                i++;
            }
        wordCount++;
        }
    }
    cout << "Word count: " << wordCount << "\n";
    wordCount = 0;
    
    // Number summation.
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
    numberSum = 0;
    
    // Custom character count.
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

int main() {
    cout << "Welcome!" << "\n\n";
    cin.get(text,textLength);
    textInfo();

    // Question mark correction.
    
    // For wh questions.
    
    for (i = 0; text[i] != '\0'; i++) {
        if (!((text[i-1] >= 'a' && text[i-1] <= 'z') || (text[i-1] >= 'A' && text[i-1] <= 'Z')) 
        && (text[i] == 'W' || text[i] == 'w') && (text[i+1] == 'H' || text[i+1] == 'h') 
        && ((text[i+2] >= 'a' && text[i+2] <= 'z') || (text[i+2] >= 'A' && text[i+2] <= 'Z'))) {
            i += 2;
            j = i;
            while (text[j] != ' ' && text[j] != '.' && text[j] != '\0')
            j++;
            if ((text[j-1] == 'r' && text[j-2] == 'e' && text[j-3] == 'v' && text[j-4] == 'e') 
            || (text[j-1] == 'g' && text[j-2] == 'n' && text[j-3] == 'i'))
            continue;
            while (text[i] != '.' && text[i] != '\0')
            i++;
            if (text[i] == '.')
            text[i] = '?';
            else if (text[i] == '\0') {
                text[i] = '?';
                text[i+1] = '\0';
            }
        }
    }

    // For do.
    for (i = 0; text[i] != '\0'; i++) {
        if ((text[i-2] != 'y' && text[i-3] != 'e' && text[i-4] != 'h' && text[i-5] != 't' && text[i-5] != 'T') && (text[i-2] != 'I') && (text[i-2] != 'u' && text[i-3] != 'o' && text[i-4] != 'Y' && text[i-4] != 'y') && (text[i] == 'D' || text[i] == 'd') && (text[i+1] == 'o') && (text[i+2] == ' ')) {
            i += 3;
            if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z')) {
                i++;
                while (text[i] != '.') {
                    i++;                   
                }
                text[i] = '?';
            }
        }
    }

    // For don't.
        for (i = 0; text[i] != '\0'; i++) {
        if ((text[i-2] != 'y' && text[i-3] != 'e' && text[i-4] != 'h' && text[i-5] != 't' && text[i-5] != 'T') && (text[i-2] != 'I') && (text[i-2] != 'u' && text[i-3] != 'o' && text[i-4] != 'Y' && text[i-4] != 'y') && (text[i-3] != 'w' && text[i-3] != 'W' && text[i-2] != 'e') && (text[i] == 'D' || text[i] == 'd') && (text[i+1] == 'o') && (text[i+2] == 'n') && (text[i+3] == '\'') && (text[i+4] == 't') && (text[i+5] == ' ')) {
            i += 6;
            if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z')) {
                i++;
                while (text[i] != '.') {
                    i++;                   
                }
                text[i] = '?';
            }
        }
    }

    // For does.
        for (i = 0; text[i] != '\0'; i++) {
        if ((text[i-2] != 't' && text[i-3] != 'I' && text[i-3] != 'i') && (text[i-2] != 'e' && text[i-3] != 'H' && text[i-3] != 'h') && (text[i-2] != 'e' && text[i-3] != 'h' && text[i-4] != 'S' && text[i-4] != 's') && (text[i] == 'D' || text[i] == 'd') && (text[i+1] == 'o') && (text[i+2] == 'e') && (text[i+3] == 's') && (text[i+4] == ' ')) {
            i += 5;
            if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z')) {
                i++;
                while (text[i] != '.') {
                    i++;                   
                }
                text[i] = '?';
            }
        }
    }

    // For doesn't.
        for (i = 0; text[i] != '\0'; i++) {
        if ((text[i-2] != 't' && text[i-3] != 'I' && text[i-3] != 'i') && (text[i-2] != 'e' && text[i-3] != 'H' && text[i-3] != 'h') && (text[i-2] != 'e' && text[i-3] != 'h' && text[i-4] != 'S' && text[i-4] != 's') && (text[i] == 'D' || text[i] == 'd') && (text[i+1] == 'o') && (text[i+2] == 'e') && (text[i+3] == 's') && (text[i+4] == 'n') && (text[i+5] == '\'') && (text[i+6] == 't') && (text[i+7] == ' ') && ((text[i+8] == 's' && text[i+9] == 'h' && text[i+10] == 'e') || (text[i+8] == 'h' && text[i+9] == 'e') || (text[i+8] == 'i' && text[i+9] == 't'))) {
            i += 8;
            if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z')) {
                i++;
                while (text[i] != '.') {
                    i++;                   
                }
                text[i] = '?';
            }
        }
    }

    // For did.
        for (i = 0; text[i] != '\0'; i++) {
        if ((text[i-2] != 'I') && (text[i-2] != 't' && text[i-3] != 'I' && text[i-3] != 'i') && (text[i-2] != 'e' && text[i-3] != 'h' && text[i-4] != 'S' && text[i-4] != 's') && (text[i-2] != 'e' && text[i-3] != 'H' && text[i-3] != 'h') && (text[i] == 'D' || text[i] == 'd') && (text[i+1] == 'i') && (text[i+2] == 'd') && (text[i+3] == ' ') && ((text[i+4] == 's' && text[i+5] == 'h' && text[i+6] == 'e') || (text[i+4] == 'h' && text[i+5] == 'e') || (text[i+4] == 'i' && text[i+5] == 't') || (text[i+4] == 'y' && text[i+5] == 'o' && text[i+6] == 'u') || (text[i+4] == 'w' && text[i+5] == 'e'))) {
            i += 4;
            if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z')) {
                i++;
                while (text[i] != '.') {
                    i++;                   
                }
                text[i] = '?';
            }
        }
    }

    // For didn't.
        for (i = 0; text[i] != '\0'; i++) {
        if ((text[i-2] != 'I') && (text[i-2] != 't' && text[i-3] != 'I' && text[i-3] != 'i') && (text[i-2] != 'e' && text[i-3] != 'h' && text[i-4] != 'S' && text[i-4] != 's') && (text[i-2] != 'e' && text[i-3] != 'H' && text[i-3] != 'h') && (text[i] == 'D' || text[i] == 'd') && (text[i+1] == 'i') && (text[i+2] == 'd') && (text[i+3] == 'n') && (text[i+4] == '\'') && (text[i+5] == 't') && (text[i+6] == ' ') && ((text[i+7] == 's' && text[i+8] == 'h' && text[i+9] == 'e') || (text[i+7] == 'h' && text[i+8] == 'e') || (text[i+7] == 'i' && text[i+8] == 't') || (text[i+7] == 'y' && text[i+8] == 'o' && text[i+9] == 'u'))) {
            i += 7;
            if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z')) {
                i++;
                while (text[i] != '.') {
                    i++;                   
                }
                text[i] = '?';
            }
        }
    }

    // Helping verb correction.
    for (i = 0; text[i] != '\0'; i++) {
    // Correct "he am" to "he is"
    if ((text[i] == 'h' || text[i] == 'H') && (text[i+1] == 'e' || text[i+1] == 'E') && (text[i+2] == ' ') && (text[i+3] == 'a' || text[i+3] == 'A') && (text[i+4] == 'm' || text[i+4] == 'M') && !((text[i+5] >= 'a' && text[i+5] <= 'z') || (text[i+5] >= 'A' && text[i+5] <= 'Z'))) {
        text[i+3] = 'i';
        text[i+4] = 's';
        i += 5;
    }
    
    // Correct "he are" to "he is"
    if ((text[i] == 'h' || text[i] == 'H') && (text[i+1] == 'e' || text[i+1] == 'E') && (text[i+2] == ' ') && (text[i+3] == 'a' || text[i+3] == 'A') && (text[i+4] == 'r' || text[i+4] == 'R') && (text[i+5] == 'e' || text[i+5] == 'E') && !((text[i+6] >= 'a' && text[i+6] <= 'z') || (text[i+6] >= 'A' && text[i+6] <= 'Z'))) {
        text[i+3] = 'i';
        text[i+4] = 's';
        j = i + 5;
        while (text[j] != '\0') {
            text[j] = text[j+1];
            j++;
        }
        i += 5;
    }

    // Correct "I is" to "I am"
    if ((text[i] == 'i' || text[i] == 'I') && (text[i+1] == ' ') && (text[i+2] == 'i' || text[i+2] == 'I') && (text[i+3] == 's' || text[i+3] == 'S') && !((text[i+4] >= 'a' && text[i+4] <= 'z') || (text[i+4] >= 'A' && text[i+4] <= 'Z'))) {
        text[i+2] = 'a';
        text[i+3] = 'm';
        i += 4;
    }

    // Correct "they is" to "they are"
    if ((text[i] == 't' || text[i] == 'T') && (text[i+1] == 'h' || text[i+1] == 'H') && (text[i+2] == 'e' || text[i+2] == 'E') && (text[i+3] == 'y' || text[i+3] == 'Y') && (text[i+4] == ' ') && (text[i+5] == 'i' || text[i+5] == 'I') && (text[i+6] == 's' || text[i+6] == 'S') && !((text[i+7] >= 'a' && text[i+7] <= 'z') || (text[i+7] >= 'A' && text[i+7] <= 'Z'))) {
        text[i+5] = 'a';
        text[i+6] = 'r';
        j = i + 7;
        if (text[j] == '\0') {
            text[j+1] = '\0';
        } else {
            while (text[j] != '\0') {
                j++;
            }
            text[j] = ' ';
            text[j+1] = '\0';
            while (j != i + 7) {
                text[j] = text[j-1];
                j--;
            }
        }
        text[i+7] = 'e';
        i += 8;
    }

    // Correct "we is" to "we are"
    if ((text[i] == 'w' || text[i] == 'W') && (text[i+1] == 'e' || text[i+1] == 'E') && (text[i+2] == ' ') && (text[i+3] == 'i' || text[i+3] == 'I') && (text[i+4] == 's' || text[i+4] == 'S') && !((text[i+5] >= 'a' && text[i+5] <= 'z') || (text[i+5] >= 'A' && text[i+5] <= 'Z'))) {
        text[i+3] = 'a';
        text[i+4] = 'r';
        if (text[i+5] == '\0') {
            text[i+6] = '\0';
        } else {
            j = i + 5;
            while (text[j] != '\0') {
                j++;
            }
            text[j] = ' ';
            text[j+1] = '\0';
            while (j != i + 5) {
                text[j] = text[j-1];
                j--;
            }
        }
        text[i+5] = 'e';
        i += 6;
    }

    // Correct "she am" to "she is"
    if ((text[i] == 's' || text[i] == 'S') && (text[i+1] == 'h' || text[i+1] == 'H') && (text[i+2] == 'e' || text[i+2] == 'E') && (text[i+3] == ' ') && (text[i+4] == 'a' || text[i+4] == 'A') && (text[i+5] == 'm' || text[i+5] == 'M') && !((text[i+6] >= 'a' && text[i+6] <= 'z') || (text[i+6] >= 'A' && text[i+6] <= 'Z'))) {
        text[i+4] = 'i';
        text[i+5] = 's';
        i += 6;
    }

    // Correct "he were" to "he was"
    if ((text[i] == 'h' || text[i] == 'H') && (text[i+1] == 'e' || text[i+1] == 'E') && (text[i+2] == ' ') && (text[i+3] == 'w' || text[i+3] == 'W') && (text[i+4] == 'e' || text[i+4] == 'E') && (text[i+5] == 'r' || text[i+5] == 'R') && (text[i+6] == 'e' || text[i+6] == 'E') && !((text[i+7] >= 'a' && text[i+7] <= 'z') || (text[i+7] >= 'A' && text[i+7] <= 'Z'))) {
        text[i+4] = 'a';
        text[i+5] = 's';
        j = i + 6;
        while (text[j] != '\0') {
            text[j] = text[j+1];
            j++;
        }
        i += 6;
    }

    // Correct "they was" to "they were"
    if ((text[i] == 't' || text[i] == 'T') && (text[i+1] == 'h' || text[i+1] == 'H') && (text[i+2] == 'e' || text[i+2] == 'E') && (text[i+3] == 'y' || text[i+3] == 'Y') && (text[i+4] == ' ') && (text[i+5] == 'w' || text[i+5] == 'W') && (text[i+6] == 'a' || text[i+6] == 'A') && (text[i+7] == 's' || text[i+7] == 'S') && !((text[i+8] >= 'a' && text[i+8] <= 'z') || (text[i+8] >= 'A' && text[i+8] <= 'Z'))) {
        text[i+5] = 'w';
        text[i+6] = 'e';
        text[i+7] = 'r';
        j = i + 8;
        if (text[j] == '\0') {
            text[j+1] = '\0';
        } else {
            while (text[j] != '\0') {
                j++;
            }
            text[j+1] = '\0';
            text[j] = ' ';
            while (j != i + 8) {
                text[j] = text[j-1];
                j--;
            }
        }
        text[i+8] = 'e';
        i += 9;
    }

    // Correct "I were" to "I was"
    if ((text[i] == 'i' || text[i] == 'I') && (text[i+1] == ' ') && (text[i+2] == 'w' || text[i+2] == 'W') && (text[i+3] == 'e' || text[i+3] == 'E') && (text[i+4] == 'r' || text[i+4] == 'R') && (text[i+5] == 'e' || text[i+5] == 'E') && !((text[i+6] >= 'a' && text[i+6] <= 'z') || (text[i+6] >= 'A' && text[i+6] <= 'Z'))) {
        text[i+2] = 'w';
        text[i+3] = 'a';
        text[i+4] = 's';
        j = i + 5;
        while (text[j] != '\0') {
            text[j] = text[j+1];
            j++;
        }
        i += 5;
    }

    // Correct "you was" to "you were"
    if ((text[i] == 'y' || text[i] == 'Y') && (text[i+1] == 'o' || text[i+1] == 'O') && (text[i+2] == 'u' || text[i+2] == 'U') && (text[i+3] == ' ') && (text[i+4] == 'w' || text[i+4] == 'W') && (text[i+5] == 'a' || text[i+5] == 'A') && (text[i+6] == 's' || text[i+6] == 'S') && !((text[i+7] >= 'a' && text[i+7] <= 'z') || (text[i+7] >= 'A' && text[i+7] <= 'Z'))) {
        text[i+4] = 'w';
        text[i+5] = 'e';
        text[i+6] = 'r';
        j = i + 7;
        if (text[j] == '\0') {
            text[j+1] = '\0';
        } else {
            while (text[j] != '\0') {
                j++;
            }
            text[j+1] = '\0';
            text[j] = ' ';
            while (j != i + 7) {
                text[j] = text[j-1];
                j--;
            }
        }
        text[i+7] = 'e';
        i += 8;
    }

    // Correct "we was" to "we were"
    if ((text[i] == 'w' || text[i] == 'W') && (text[i+1] == 'e' || text[i+1] == 'E') && (text[i+2] == ' ') && (text[i+3] == 'w' || text[i+3] == 'W') && (text[i+4] == 'a' || text[i+4] == 'A') && (text[i+5] == 's' || text[i+5] == 'S') && !((text[i+6] >= 'a' && text[i+6] <= 'z') || (text[i+6] >= 'A' && text[i+6] <= 'Z'))) {
        text[i+3] = 'w';
        text[i+4] = 'e';
        text[i+5] = 'r';
        j = i + 6;
        if (text[j] == '\0') {
            text[j+1] = '\0';
        } else {
            while (text[j] != '\0') {
                j++;
            }
            text[j+1] = '\0';
            text[j] = ' ';
            while (j != i + 6) {
                text[j] = text[j-1];
                j--;
            }
        }
        text[i+6] = 'e';
        i += 7;
    }

    // Correct "she were" to "she was"
    if ((text[i] == 's' || text[i] == 'S') && (text[i+1] == 'h' || text[i+1] == 'H') && (text[i+2] == 'e' || text[i+2] == 'E') && (text[i+3] == ' ') && (text[i+4] == 'w' || text[i+4] == 'W') && (text[i+5] == 'e' || text[i+5] == 'E') && (text[i+6] == 'r' || text[i+6] == 'R') && (text[i+7] == 'e' || text[i+7] == 'E') && !((text[i+8] >= 'a' && text[i+8] <= 'z') || (text[i+8] >= 'A' && text[i+8] <= 'Z'))) {
        text[i+5] = 'a';
        text[i+6] = 's';
        j = i + 7;
        while (text[j] != '\0') {
            text[j] = text[j+1];
            j++;
        }
        i += 7;
    }

    // Correct "They am" to "They are"
    if ((text[i] == 'T' || text[i] == 't') && (text[i+1] == 'H' || text[i+1] == 'h') && (text[i+2] == 'E' || text[i+2] == 'e') && (text[i+3] == 'Y' || text[i+3] == 'y') && (text[i+4] == ' ') && (text[i+5] == 'A' || text[i+5] == 'a') && (text[i+6] == 'M' || text[i+6] == 'm') && !((text[i+7] >= 'A' && text[i+7] <= 'Z') || (text[i+7] >= 'a' && text[i+7] <= 'z'))) {
        text[i+6] = 'r';
        j = i + 7;
        if (text[j] == '\0') {
            text[j+1] = '\0';
        } else {
            while (text[j] != '\0') {
                j++;
            }
            text[j+1] = '\0';
            text[j] = ' ';
            while (j != i + 7) {
                text[j] = text[j-1];
                j--;
            }
        }
        text[i+7] = 'e';
        i += 8;
    }
    }

    cout << "\n" << "Corrected text" << "\n";
    cout << "------------------------------------------------";
    cout << "\n\n" << text << "\n";
    textInfo();
}