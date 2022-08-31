/**
 * @file MonoAlphabeticCipher.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Implementation of Monoalphabetic Cipher Security Algorithm According to Lecture Sheet
 * @version 0.1
 * @date 2021-02-09
 * @since TuesDay: 10:10 AM
 * @copyright Copyright (c) 2021
 * Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */

#include <iostream>
#include <cstring>
#include <conio.h>

/*Driver Code*/
int main(void){
    system("cls");
    char pt[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char ct[26] = {'D', 'K', 'V', 'Q', 'F', 'I', 'B', 'J', 'W', 'P', 'E', 'S', 'C','X', 'H', 'T', 'M', 'Y', 'A', 'U', 'O', 'L', 'R', 'G', 'Z', 'N'};
    char p[20] = {'\0'}, c[20] = {'\0'}, r[20] = {'\0'};
    int i, j;
    printf("Enter the plain text:");
    gets(p);
    for(i = 0; i<strlen(p); i++){
        if(islower(p[i])){
            p[i] = toupper(p[i]);
        }
    }
    //converting plain text into cipher text (encryption)
    for (i = 0; i < strlen(p); i++){
        for (j = 0; j < 26; j++){
            if (pt[j] == p[i]){
                c[i] = ct[j];
            }
        }
    }
    printf("\nCipher text is: %s", c);

    //converting cipher text into plain text (decryption)
    for (i = 0; i < strlen(c); i++)
    {
        for (j = 0; j < 26; j++){
            if (ct[j] == c[i]){
                r[i] = pt[j];
            }
        }
    }
    printf("\n\nPlain text is: %s", r);
    getche();
    return 0;
}