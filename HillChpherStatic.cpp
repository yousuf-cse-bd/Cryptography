/**
 * @file HillChpherStatic.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Implementation of Hill Chpher Static Algorithm Encryption Part
 * @version 0.1
 * @date 2021-03-09
 * @since TuesDay; 10:10 PM
 * @copyright Copyright (c) 2021
 * Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */

#include <iostream>
using namespace std;

int main(int argc, char const *argv[]){
    system("cls");
    int alphIndex, j, k;
    char i;
    char mainMessage[3] = {'H', 'I'};
    int array[2];
    cout << "Main Message: " << mainMessage << endl;
    cout << "Corresponding Matrix:" << endl;
    for (j = 0; j < 3; j++){
        for (i = 'A'; i <= 'Z'; i++){
            if (mainMessage[j] == i){
                alphIndex = i - 65;
                array[j] = alphIndex;
            }
        }
    }

    cout << array[0] << endl;
    cout << array[1] << endl;
    int myArray[2][1];

    myArray[0][0] = array[0];
    myArray[1][0] = array[1];

    int keyWord[2][2] = {2, 1, 3, 4};
    cout << "Key Word Below:" << endl;
    for (i = 0; i < 2; i++){
        for (j = 0; j < 2; j++){
            cout << keyWord[i][j] << " ";
        }
        cout << endl;
    }

    int productMat[2][1];
    int sum = 0;
    for (i = 0; i < 2; i++){
        for (j = 0; j < 1; j++){
            for (k = 0; k < 2; k++){
                sum = sum + keyWord[i][k] * myArray[k][j];
            }
            productMat[i][j] = sum;
            sum = 0;
        }
    }

    cout << "Product of matix below:" << endl;
    for (i = 0; i < 2; i++){
        for (j = 0; j < 1; j++){
            cout << productMat[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Mod of 26 the matrix:" << endl;
    int mod26[2][1];
    for (i = 0; i < 2; i++){
        for (j = 0; j < 1; j++){
            mod26[i][j] = productMat[i][j] % 26;
            cout << mod26[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nEncryption the main message: ";

    if (mod26[0][0] < mod26[1][0]){
        for (i = 0; i < 26; i++){
            for (j = 0; j < 2; j++){
                for (k = 0; k < 1; k++){
                    if (mod26[j][k] == i){
                        char alphIndex = i + 65;
                        cout << alphIndex;
                    }
                }
            }
        }
    }
    else{
        for (i = 25; i >= 0; i--){
            for (j = 0; j < 2; j++){
                for (k = 0; k < 1; k++){
                    if (mod26[j][k] == i){
                        char alphIndex = i + 65;
                        cout << alphIndex;
                    }
                }
            }
        }
    }

    return 0;
}
