/**
 * @file RSA_Algorithm.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Implementation of RSA_Algorithm RSA=(Rivest–Shamir–Adleman)
 * @version 0.1
 * @date 2021-03-23
 * @since TuesDay; 10:10 PM
 * @copyright Copyright (c) 2021
 * Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
/*This function most inportaing for memory managenmet*/
long long int multiply(int base, int power, int moduler){
    long long int result = 1;
    for(int i = 1; i<= power; i++)
    {
        result = result * base;
        result = result % moduler;
    }
    return result;
}
/*Check Prime Number Simply*/
bool isPrime(long long int n){
    bool flag = false;
    for(int i = 2; i*i <= n ;i++){
        if(n % i == 0){
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
    long long p,q, c,d, e,m, n ,fi_n;
    cout<<"Enter First Prime Number Here, P: ";
    cin>>p;

    cout<<"Enter Second Prime Number, Q: ";
    cin>>q;

    // p = 3;
    // q = 11;

    if(isPrime(p) == true && isPrime(q) == true){
        cout<<"Enter Value of, e: ";
        cin>>e;
        // e = 3;
        n = (p * q);
        fi_n = (p - 1) *(q - 1);
        cout<<"Enter Value of, M: ";
        cin>>m;
        if(m < n && 1<e && e<fi_n && __gcd(e, fi_n) == 1 ){
            
            // c = (long long) pow(m, e) % n;
            c = multiply(m, e, n);
            cout<<"Encrypted Value: "<<c<<endl;
            cout<<"Public Key: ["<<e<<", "<<n<<"]\n";

            int i = 0;
            while (true)
            {
                i++;
                if(e*i % fi_n == 1){
                    d = i;
                    break;
                }
            }

            // m = (long long) pow(c, d) % n;
            m = multiply(c, d, n);
            cout<<"\nPrivate Key: ["<<d<<", "<<n<<"]\n";
            cout<<"Decrypted Value: "<<m<<endl;
        }
        else{
            cout<<"RSA Operation Not Possible..!"<<endl;
        }
    }
    else{
        cout<<"The Number Have to be Prime Number...!"<<endl;
    }

    return 0;
}