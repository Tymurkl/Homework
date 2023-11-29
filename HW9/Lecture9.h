#pragma once
void translateArray(int numbers[], int size) {
    for (int i = 0; i < size; ++i) {
        if (numbers[i] > 0) {
            numbers[i] *= 2;
        } else {
            numbers[i] = 0;
        }
    }
}
void toUppercase(char str[], int length){
    for (int m = 0; m < length; ++m) {
        if (islower(str[m]))
            str[m] = toupper(str[m]);

    }
}
bool isPalindrome(std:: string str)
{
    for(int i = 0; i <= str.length()-1; i++)
    {
        if(str[i] != str[str.length()-1-i])
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}

void parseStringLetters(const char str[], int& vowelsCount, int& consonantsCount) {
    vowelsCount = 0;
    consonantsCount = 0;

    for (int i = 0; str[i] != '\0'; ++i) {
        char ch = tolower(str[i]);
        if (isalpha(ch)) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'|| ch=='y') {
                vowelsCount++;
            } else {
                consonantsCount++;
            }
        }
    }
}
bool isEqual(const char str1[], const char str2[]){
    if (strlen(str1) != strlen(str2)) {
        return false;
    }

    for(int e = 0; str1[e] != '\0'; e++){
        if(str1[e] != str2[e]){
            return false;
        }
    }
    return true;
}

