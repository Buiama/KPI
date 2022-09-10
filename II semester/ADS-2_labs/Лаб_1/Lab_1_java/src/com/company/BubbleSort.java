package com.company;

public class BubbleSort {

    public static void bubbleSort(int[] arr) {
        int k = 0; // int buf;
        int comparison = 0, swap = 0;
        boolean isSorted = false; // проверка на отсортированность, залог естественности

        while(!isSorted) { // идеальный пузырек личной разработки
            isSorted = true;

            for (int i = arr.length - 1; i > k; i--) {//int i = 0; i <arr.length - k - 1; i++  тогда в свапе тоже с плюсом
                comparison++; // кол-во сравнений
                if (arr[i - 1] > arr[i]) {
                    isSorted = false; // если без/c использования третьей переменной:

                    arr[i] += arr[i-1]; // buf = arr[i - 1];
                    arr[i-1] = arr[i] - arr[i-1]; // arr[i - 1] = arr[i];
                    arr[i] -= arr[i-1]; // arr[i] = buf;
                    swap++; // кол-во перестановок
                }
            }
            k++; // самодельный счетчик
        }
        System.out.println("\n\nComparisons = " + comparison + "; Swaps = " + swap);
    }
}
