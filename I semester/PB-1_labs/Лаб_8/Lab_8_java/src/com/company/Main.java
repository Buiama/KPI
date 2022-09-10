package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[][] b = new int[n][n];
        for(int i=0; i<n;i++) {
            for(int j=0;j<n;j++) {
                b[i][j] = in.nextInt();
            }
        }
        output(n,n,b);
        sort(n,b);
        output(n,n,b);
        int[][] x = new int[n][1];
        vectorX(b,x,n);
        output(n,1,x);
    }

    public static void output(int m, int n, int[][] matrix) {
        for(int i=0; i<m;i++) {
            System.out.println();
            for(int j=0;j<n;j++) {
                System.out.print(matrix[i][j]+" ");//System.out.printf("%4d",matrix[i][j])
            }
        }
        System.out.println();
    }

    public static void sort(int n, int[][] matrix) {
        boolean isSorted = false;
        int[] buf = new int[n];
        while(!isSorted) {
            isSorted = true;
            for (int i = 0; i < n-1; i++) {
                if(matrix[i][0] < matrix[i+1][0]){
                    isSorted = false;

                    for(int j=0;j<n;j++) {
                       buf[j]=matrix[i][j];
                       matrix[i][j]=matrix[i+1][j];
                       matrix[i+1][j]=buf[j];
                    }
                }
            }
        }
    }
    public static void vectorX(int[][] matrix, int[][] vector, int n) {
        for(int i=0;i<n;i++) {
            vector[i][0]=matrix[i][i];
        }
    }
}
