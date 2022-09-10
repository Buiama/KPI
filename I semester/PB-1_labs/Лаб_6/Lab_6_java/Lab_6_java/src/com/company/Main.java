package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();//вводимо значення
        int b = in.nextInt();
        int c = in.nextInt();
        System.out.println(nsd(nsd(a,b),c));//виводимо результат, використовуючи функцію
    }
    public static int nsd(int a, int b) {//створюємо функцію по алгоритму Евкліда
        while(a!=0 && b!=0) {
            if(a>b) {
                a%=b;
            }
            else {
                b%=a;
            }
        }
        return a+b;//повертаємо НСД введених двох значень
    }
}
