/**
 * @file RouteCipherSpiralTravarse.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Implement of ROUTE Cipher algorithm using spiral or selical sraversing
 * @version 0.1
 * @date 2022-08-30
 * @since TuesDay; 09: 00AM
 * @copyright Copyright (c) 2022
 * Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */

#include <iostream>
using namespace std;
/*Route Cipher Algorithm Using Spiral or Helical Traverse*/
void routeCipherText(char plainText[][5],unsigned int rowColumnSize){
    cout<<"Cipher Text: ";
    int row = 0;
    while(row < rowColumnSize){
        /*Printing: 'W','D','V','F','T'*/
        for(int column = row; column < rowColumnSize; column++){
            cout<<plainText[row][column];
        }
        /*Printing: FLEEA*/
        for(int column = row + 1; column < rowColumnSize; column++){
            cout<<plainText[column][rowColumnSize-1];
        }
        /*Printig: DOE*/
        for(int column = rowColumnSize - 2; column >= row; column--){
            cout<<plainText[rowColumnSize-1][column];
        }
        /*Printing: RAE*/
        for(int column = rowColumnSize - 2; column > row; column --){
            cout<<plainText[column][row];
        }
        // cout<<endl;
        row++;
        rowColumnSize--;
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
