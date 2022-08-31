/**
 * @file RailFenceCipherAlg.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Implementation of RailFence Cipher Algorithm
 * @version 0.1
 * @date 2022-02-02
 * @since TuesDay; 10:10 AM
 * @copyright Copyright (c) 2022
 * Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#include <string.h>
#include <conio.h>
using namespace std;

void railFenceCipherAlg(){

    int i, j, len, railsKey, count;
    char plainText[] = "THISISASECRETMESSAGE";
    cout << "PlianText: " << plainText << endl;
    railsKey = 3;
    cout << "RailsKey Value: " << railsKey << endl;
    len = strlen(plainText);
    // cout<<len<<endl;
    char railCipher[railsKey][len];
    for (i = 0; i < railsKey; i++){
        for (j = 0; j < len; j++){
            railCipher[i][j] = 0;
        }
    }
    count = 0;
    j = 0;
    while (j < len){
        if (count % 2 == 0){
            for (i = 0; i < railsKey; i++){
                railCipher[i][j] = plainText[j];
                // cout<<railCipher[i][j]<<" ";
                j++;
            }
        }
        else{
            for (i = railsKey - 2; i > 0; i--){
                railCipher[i][j] = plainText[j];
                // cout<<"*"<<railCipher[i][j]<<" ";
                j++;
            }
        }
        count++;
    }

    cout << "Cipher Text: ";
    for (i = 0; i < railsKey; i++){
        for (j = 0; j < len; j++){
            if (railCipher[i][j] != 0){
                cout << railCipher[i][j];
            }
        }
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    system("cls");
    railFenceCipherAlg();
    getche();
    return 0;
}
