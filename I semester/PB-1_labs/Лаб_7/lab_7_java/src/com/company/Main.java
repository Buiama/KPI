package com.company;

//import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Amount of elements:");
        int n = in.nextInt();
        int[] b = new int[n];
        System.out.println("Elements:");
        for(int i=0; i<n;i++) {
            b[i] = in.nextInt();
        }
        //System.out.println(Arrays.toString(b));
        System.out.println("Array B("+n+"):");
        output(b);
        System.out.println("Array MinMax[min,max,minIndex]:");
        output(minMax(b));
        //System.out.println("max-min = "+ subtraction(minMax(b)[0],minMax(b)[1]));
        System.out.println("max-min = "+ subtraction(minMax(b)));
        System.out.println("Final array:");
        output(replace(b));
    }

    public static void output(int[] arr) {
        for (int i : arr) {//for(int i=0; i<arr.length; i++) - тоже самое, только сокращенно
            System.out.println(i);
        }
    }

    public static int[] minMax(int[] arr) {
        int[] minMax = new int[3];
        minMax[0]=arr[0];//min
        minMax[1]=arr[0];//max
        for(int i=1;i<arr.length;i++) {//int i : arr - на одну итерацию больше
            if(arr[i]<minMax[0]) {
                minMax[0]=arr[i];
                minMax[2]=i;
                System.out.println("[2] = "+i);
            }
            if(arr[i]>minMax[1]) {
                minMax[1]=arr[i];
            }
        }
        return minMax;
    }

    public static int subtraction(int[] minMax) {
        return minMax[1]-minMax[0];
    }
    /*
    * public static int subtraction(int min, int max) {
    *   return max-min;
    * }
    * */

    public static int[] replace(int[] arr) {
        int tmp = arr[arr.length-1];
        arr[arr.length-1] = minMax(arr)[0];
        arr[minMax(arr)[2]]=tmp;
        return arr;
    }
}

/*
public static int min(int[] arr) {
        int min=arr[0];
        for(int i=1;i<arr.length;i++) {//int i : arr - на одну итерацию больше
            if(arr[i]>min) {
                min=arr[i];
            }
        }
        return min;
    }
*/

