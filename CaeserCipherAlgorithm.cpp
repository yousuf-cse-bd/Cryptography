/**
 * @file CaeserCipherAlgorithm.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Implement: Caesar Cipher Algorithm Encryption and Decryption
 * @version 0.1
 * @date 2022-08-30
 * @since TuesDay; 07:54 PM
 * @copyright Copyright (c) 2022
 * Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
using namespace std;
/*Caesar Cipher: Encryption Part*/
string encrypt(string text, int key){
    string cipherText;
    //Traverse Text
    for(int i = 0; i< text.length(); i++){
        if(isupper(text[i])){
            cipherText += (text[i] + key - 'A') % 26 + 'A';
        }
        else if(islower(text[i])){
            cipherText += (text[i] + key - 'a') % 26 + 'a';
        }
        else{
            cipherText += text[i];
        }
    }
    return cipherText;
}
/*Caesar Cipher: Decryption Part*/
string decrypt(string ciperText, int key){
    string plainText;
    for(int i = 0; i<ciperText.length(); i++){
        if(isupper(ciperText[i])){
            plainText += (ciperText[i] - 'A' - key + 26) % 26 + 'A';
        }
        else if(islower(ciperText[i])){
            plainText += (ciperText[i] - 'a' - key + 26) % 'a' + 97;
        }
        else{
            plainText += ciperText[i];
        }
    }
    return plainText;
}

int main(int argc, char const *argv[]){
    system("cls");
    string text = "MY CAT HAS FLEAS";
    unsigned int key = 4;
    cout<<"Text: "<<text<<endl;
    cout<<"Key: "<<key<<endl;
    cout<<"Cipher Text: "<<encrypt(text, key)<<endl;
    cout<<"Main Text: "<<decrypt(encrypt(text, key), key)<<endl;
    return 0;
}
