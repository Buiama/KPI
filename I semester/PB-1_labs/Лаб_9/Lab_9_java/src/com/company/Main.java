package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Your string: ");
        String str = in.nextLine();
        System.out.print("Amount of letters in words: ");
        int k = in.nextInt();
        String[] words = str.split("\\W+"); // Розбиваємо рядок на масив слів без зайвих символів
        System.out.println("\nWords from the entered sentence:");
        cutWords(words);
        System.out.println("\nwords of "+k+" letters:");
        onlyWords(words,k);
    }
    public static void cutWords(String[] words) { // вивід масиву
        for(int i = 0; i<words.length;i++) {//or we can use String word:words
            System.out.println(words[i]);
        }
    }
    public static void onlyWords(String[] words, int k) { // виводимо лише потрібні слова
        for (String word : words) {//or we can use int i = 0; i<words.length; i++
            if (word.length() == k) {
                System.out.println(word);
            }
        }
    }
}
