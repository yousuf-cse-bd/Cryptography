/**
 * @file PrimitiveRootsFound.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Primitive Roots Calculation
 * @version 0.1
 * @date 2022-03-20
 * @since SaturDay; 10:10 PM
 * @copyright Copyright (c) 2021
 * Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */

#include <iostream>
#include <cmath>
#include <conio.h>
using namespace std;
/*This part most importaint*/
long long int multiply(int base, int power, int moduler){
    long long int result = 1;
    for (int i = 1; i <= power; i++){
        result = result * base;
        result = result % moduler;
    }
    return result;
}
/*Simple checking prime number*/
bool isPrime(long long int n){
    bool flag = false;
    for (int i = 2; i*i <= n; i++){
        if (n % i == 0){
            flag = true;
        }
    }
    if(flag == false){
        return true;
    }
    else{
        return false;
    }
}

int main(void){
    system("cls");
    int p, a;
    cout << "Enter A Prime Number Here: ";
    cin >> p;
    if (isPrime(p)){
        a = 1;
        while (a != p){
            printf("For %d Roots: ", a);
            for (int i = 1; i < p; i++){
                // long long int q = (long long int)pow(a, i) % p;
                long long int q = multiply(a, i, p);
                if (q == 1){
                    cout << q << " ";
                    break;
                }
                else{
                    cout << q << " ";
                }
                q = 0;
            }
            a++;
            cout << endl;
        }
    }
    else{
        cout<<"Your Number Must Be Prime Numner...!"<<endl;
    }
    getche();
    return 0;
}

