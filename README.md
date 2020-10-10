# algoritm


This repo include different type of algoritm at codeforce.com.


#Number of Subsequences
You are given a string s

consisting of lowercase Latin letters "a", "b" and "c" and question marks "?".

Let the number of question marks in the string s
be k. Let's replace each question mark with one of the letters "a", "b" and "c". Here we can obtain all 3k possible strings consisting only of letters "a", "b" and "c". For example, if s="ac?b?c" then we can obtain the following strings: ["acabac", "acabbc", "acabcc", "acbbac", "acbbbc", "acbbcc", "accbac", "accbbc", "accbcc"]

Your task is to count the total number of subsequences "abc" in all resulting strings. Since the answer can be very large, print it modulo 109+7. A subsequence of the string t
is such a sequence that can be derived from the string t after removing some (possibly, zero) number of letters without changing the order of remaining letters. For example, the string "baacbc" contains two subsequences "abc" — a subsequence consisting of letters at positions (2,5,6) and a subsequence consisting of letters at positions (3,5,6).
