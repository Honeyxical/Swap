#include <iostream>

using namespace std;

void swap(char str[], char buffer[]);

void changeNumOnSym(int num, int position, char str[], char buffer[]);

void strCpyToEnd(char str1[], char str2[], int position);

int getLength(char str[]);

void strCpy(char str[], char buffer[]);


int main() {
    char str[255] = {0};
    char buffer[255] = {0};

    cout << "Enter string: ";
    cin >> str;

    swap(str, buffer);
    cout << str;
    return 0;
}

void swap(char str[], char buffer[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i])) {
            changeNumOnSym(str[i] - '0', i, str, buffer);
            i = 0;
        }
    }
}

void changeNumOnSym(int num, int position, char str[], char buffer[]) {
    for (int i = 0; i < position; i++) {
        buffer[i] = str[i];
    }
    for (int i = position; i < position + num; i++) {
        if (num % 2 == 0) {
            buffer[i] = '+';
        } else {
            buffer[i] = '-';
        }
    }

    strCpyToEnd(str, buffer, position);
    strCpy(str, buffer);

}

void strCpyToEnd(char str[], char buffer[], int position){
    int str2length  = getLength(buffer);
    int j = 1;
    for(int i = position + 1; str[i] != '\0'; i++){
        buffer[(str2length - 1) + j] = str[i];
        j++;
    }

}

int getLength(char str[]){
    int i = 0;
    while(str[i] != '\0'){
        i++;
    }
    return i;
}

void strCpy(char str[], char buffer[]){
    for(int i = 0; buffer[i] != '\0'; i++){
        str[i] = buffer[i];
    }
    buffer = {0};
}
