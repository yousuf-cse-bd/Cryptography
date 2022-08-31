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
import java.util.Scanner;

public class RSA {

    static boolean isPrime(long n) {
        short flag = 0;
        for (int i = 2; i*i <= n; i++) {
            if (n % i == 0) {
                flag = 1;
            }
        }
        if (flag == 0) {
            return true;
        } else {
            return false;
        }
    }

    public static void main(String[] args) {
        // (p = 3, q = 11, e = 7, m = 31 Tested)
        int i, e;
        long p, q, m, c, d, n, fi_n;
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter First Prime Numbner Here, P: ");
        p = scanner.nextLong();

        System.out.print("Enter Second Prime Number Here, Q: ");
        q = scanner.nextLong();

        if (isPrime(p) == true && isPrime(q) == true) {
            System.out.print("Enter Value of e: ");
            e = scanner.nextInt();
            System.out.print("\nEnter The Value of M: ");
            m = scanner.nextLong();
            n = p * q;
            fi_n = (p - 1) * (q - 1);
            if (m < n) {
                c = (long) Math.pow(m, e) % n;
                System.out.println("\nEncrypted Value, C: " + c);
                i = 0;
                while (true) {
                    i++;
                    if (e * i % fi_n == 1) {
                        d = i;
                        break;
                    }
                }

                System.out.println("Public Key: [" + e + ", " + n + "]");
                System.out.println("Private Key: [" + d + ", " + n + "]");
                m = (long) Math.pow(c, d) % n;
                System.out.println("Decrypted Value D:" + m);
            } else {
                System.out.println("RSA Operation not Possible..!");
            }

        } else {
            System.out.println("Not Prime...!");
        }
        scanner.close();
    }
}
