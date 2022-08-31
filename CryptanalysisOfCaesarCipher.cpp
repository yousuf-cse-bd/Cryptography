/**
 * @file CryptanalysisOfCaesarCipher.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief BruteForceAttack: Cryptanalysis of Caesar Cipher
 * @version 0.1
 * @date 2021-01-26
 * @since FriDay; 10:10 PM
 * @copyright Copyright (c) 2022
 * Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */

#include <iostream>
#include <string.h>
using namespace std;

//Encryption to PlainText Method
string encrypt(string x, int n){
    string cipher = "";

    for (int i = 0; i < x.length(); i++){
        /*x[i] read ASCII value of corresponding alphabet */
        if (isupper(x[i])){
            cipher += (x[i] + n - 'A') % 26 + 'A';  
        }                  
        else if (islower(x[i])){
            cipher += (x[i] + n - 'a') % 26 + 'a'; 
        }                  
        else{
            cipher += x[i]; /*Special Symbol and Space on change*/
        }
    }
    return cipher;
}

//Decrypt the Cipher Text Using BruteForceAttack Agorithm.
void decryptUsingBruteForceAttack(string x){
    cout <<"Possible Key: Plain Text:"<<endl;
    string text;
    /*Ensure! key should be consist 1 to 26.*/
    for (unsigned int possibleKey = 1; possibleKey <= 26; possibleKey++)
    {
        text = "";
        for (unsigned int i = 0; i < x.length(); i++)
        {
            if (isupper(x[i]))
            {
                if ((x[i] - possibleKey - 65) < 0){
                    text += 91 + (x[i] - possibleKey - 65);
                }
                else{
                    text += ((x[i] - possibleKey - 65) % 26) + 65;
                }
            }
            else if (islower(x[i]))
            {
                if ((x[i] - possibleKey - 97) < 0){
                    text += 123 + (x[i] - possibleKey - 97);
                }
                else{
                    text += ((x[i] - possibleKey - 97) % 26) + 97;
                }
            }
            else{
                text += x[i];
            }
        }
        /*Display each PlainText Possible key*/
        cout<<possibleKey<<"\t:\t"<<text<<endl;
    }
}
/*Driver Code*/
int main(void){
    system("cls");
    int key;
    string text;
    cout << "Enter Text Here: ";
    getline(cin, text);
    cout << "Enter Key Here: ";
    cin >> key;

    string cipher = encrypt(text, key);
    cout << "Ciper Text Here : " << cipher << "\n\n";

    decryptUsingBruteForceAttack(cipher);

    return 0;
}