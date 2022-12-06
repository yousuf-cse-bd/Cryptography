/**
 * @file MonoAlphbeticCipher2.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Mono Alphabetic Cipher Algorithm type of Substitute Method
 * @version 0.1
 * @date 2022-12-07
 * @since TuesDay; 12:47 AM
 * @copyright Copyright (c) 2022
 * Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#pragma pack(0)
using namespace std;

class MonoAlphabeticCipher{
private:
    const string alphanumeric {" abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    const string key {"$XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};
    string plainText{}, cipherText{};
public:
    void inputeMessage(void){
        cout<<"Enter your secret message here: ";
        getline(cin, plainText);
    }
    void encyptingMethod(void){
        cout<<"\tEncrypting the message..."<<endl;
        for(auto letter: plainText){
            size_t position {alphanumeric.find(letter)};
            if(position != string :: npos){
                cipherText.push_back(key.at(position));
            }else{
                cipherText.push_back(letter);
            }
        }
        cout<<"Encrypted the message: "<<cipherText<<endl;
    }
    void decryptingMethod(void){
        plainText.clear();
        cout<<"\tDecrypting the message..."<<endl;
        for(auto letter: cipherText){
            size_t position {key.find(letter)};
            if(position != string :: npos){
                plainText.push_back(alphanumeric.at(position));
            }else{
                plainText.push_back(letter);
            }
        }
        cout<<"Decrypted the message: "<<plainText<<endl;
    }
};

int main(int argc, char const *argv[]){
    /* code */
    system("cls");
    MonoAlphabeticCipher secretObject;
    secretObject.inputeMessage();
    secretObject.encyptingMethod();
    secretObject.decryptingMethod();
    system("pause > 0");
    return 0;
}
