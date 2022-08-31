/**
 * @file MidLabTest.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Implementation of Monoalphabetic Cipher Security Algorithm
 * @version 0.1
 * @date 2021-03-16
 * @since TuesDay; 10:10 AM
 * @copyright Copyright (c) 2021
 * Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */

#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[]){
    system("cls");
    char givenText[27] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
                           'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char key[27] = {'M', 'D', 'Y', 'O', 'S', 'F', 'A', 'L', 'I', 'B', 'N', 'P', 'R', 
                    'Q', 'T',  'V', 'W', 'X', 'Z', 'G', 'H', 'L', 'R', 'J', 'C', 'E'};
    
    char message[100] = {'\0'};

    cout<<"Enter Your Message Here: ";
    cin>>message;
    for(int i = 0; i < strlen(message); i++){
        if(islower(message[i])){
            message[i] = toupper(message[i]);
        }
    }

    char cipherText[strlen(message)+1] = {'\0'};
    //converting plain text into cipher text (encryption)
    for (int i = 0; i < strlen(message); i++){
        for (int j = 0; j < strlen(key); j++){
            if (message[i] == givenText[j]){
                cipherText[i] = key[j];
            }
        }
    }
    printf("Encrypted Message: %s\n", cipherText);

    
    return 0;
}
