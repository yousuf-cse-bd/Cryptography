/**
 * @file HillCipherUserInPut.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Implementation of Hill Chpher User Input Algorithm Encryption Part
 * @version 0.1
 * @date 2021-03-09
 * @since TuesDay; 10:10 AM
 * @copyright Copyright (c) 2021
 * Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */


#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[]){
    system("cls");
    char plainText[3];
    cout << "Enter Your Plain Text Here(2 Lenth): ";
    cin >> plainText;
    if (strlen(plainText) == 2){
        int ciphertText[2][1] = {};
        int key[2][2] = {2, 1, 3, 4};
        cout << "Given Key for 2x2 Matrix:" << endl;
        for (int i = 0; i < 2; i++){
            //toUpper
            if(islower(plainText[i])){
                plainText[i] = toupper(plainText[i]);
            }
            for (int j = 0; j < 2; j++){
                cout << key[i][j] << "\t";
            }
            cout<<endl;
        }

        //Plaintext --> message(int) column matrix
        int message[2][1];
        cout << "\nColumn Matrix" << endl;
        for (int i = 0; i < 2; i++)
        {
            message[0][i] = plainText[i] - 65;
            cout << message[i][0] << endl;
        }

        ///Matrix Multiplication
        for (int i = 0; i < 2; i++){
            for (int j = 0; j < 1; j++){
                for (int k = 0; k < 2; k++){
                    ciphertText[i][j] = ciphertText[i][j] + key[i][k] * message[k][j];
                }
            }
        }
        ///Encryption
        cout << "After Encryption: ";
        for (int i = 0; i < 2; i++){
            cout << (char)((ciphertText[i][0] % 26) + 65);
        }
    }
    else{
        cout<<strlen(plainText)<<endl;
        cout << "It Support Only 2 Length...!" << endl;
    }

    return 0;
}
