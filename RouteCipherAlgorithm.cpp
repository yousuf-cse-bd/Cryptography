/**
 * @file RouteCipherAlgorithm.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Route Cipher: Read message from top right corner down and to the left
 * @version 0.1
 * @date 2022-08-30
 * @since TuesDay; 05:13 PM
 * @copyright Copyright (c) 2022
 * Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */

#include <iostream>
using namespace std;
/*Route Cipher Algorithm Traverse*/
void routeCipherText(char plainText[][5],unsigned int rowColumnSize){
    cout<<"Cipher Text: ";
    int column = rowColumnSize - 1;
    while(column >=0 ){
        /*Print: Up to Down*/
        for(int row = 0; row <= column; row++){
            cout<<plainText[row][column];
            // cout<<' ';
        }
        /*Print: Right to Left*/
        for(int row = column - 1; row >= 0; row--){
            cout<<plainText[column][row];
            // cout<<' ';
        }
        column --;
        // cout<<endl;
    }
}
/*Driver Code*/
int main(int argc, char const *argv[]){
    /* code */
    system("cls");
    const unsigned int rowColumnSize = 5;
    char plainText[rowColumnSize][rowColumnSize] = {{'W','D','V','F','T'},
                                                    {'E','I','E','L','O'},
                                                    {'A','S','R','E','N'},
                                                    {'R','C','E','E','C'},
                                                    {'E','O','D','A','E'}};
    printf("Plain Text: %s\n", plainText);
    routeCipherText(plainText, rowColumnSize);                                                
    return 0;
}
