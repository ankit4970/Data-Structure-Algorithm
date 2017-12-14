//
// Created by ankit on 9/20/2017.
//
#include "common.h"
#include <cstring>
#include <chrono>
#include <vector>



#if 0
bool isSubsequence(char* s, char* t)
{
    while (*t)
    {
        s = s + (*s == *t++);
    }
    return !*s;
}
#endif
/* ************************************************************************************************
 * Reverses a given string
   ex. input : string
       output : gnirts
 ************************************************************************************************/
void reverse(char *begin, char *end)
{
    char temp;
    while (begin < end)
    {
        temp = *begin;
        *begin++ = *end;
        *end-- = temp;
    }
}

/* ************************************************************************************************
 * Reverse the words in a sentence
   ex. input : this is a string
       output : string a is this
 ************************************************************************************************/
void stringReverseWords(char *string)
{
    char *begin = string;
    char *temp = string;

    while(*temp)
    {
        temp++;
        if(*temp == '\0')
        {
            reverse(begin, temp-1);
        }
        else if(*temp == ' ')
        {
            reverse(begin, temp-1);
            begin = temp+1;
        }
    }

    reverse(string, temp-1);
}

/* ************************************************************************************************
 * Check if a string is palindrome
   i.e. input : aaddddaa output : is palindrome
       input : abcded   output : is not palindrome
 ************************************************************************************************/
void isPalindrome(char str[])
{
    // Start from leftmost and rightmost corners of str
    int l = 0;
    int h = strlen(str) - 1;

    // Keep comparing characters while they are same
    while (h > l)
    {
        if (str[l++] != str[h--])
        {
            cout << str << "is Not Palindrome\n";
            return;
        }
    }
    cout << str << "is palindrome" << endl;
}

/* ************************************************************************************************
 * Check if a string is palindrome
   i.e. input : aaddddaa output : is palindrome
       input : abcded   output : is not palindrome
 ************************************************************************************************/
void maxOccuringcharacter(char *str)
{
    int map[256]= {};
    int maximum = 0;
    char result = '\0';

    for (int i=0 ; i < strlen(str) ; i++)
    {
        map[str[i]]++;
        if(maximum < map[str[i]])
        {
            maximum = map[str[i]];
            result = str[i];
        }
    }

    cout << "Maximum occuring character in \"" << str << "\" is : " << result << ' ' <<maximum << " times" << endl;
}

/* ************************************************************************************************
 * removeSpaces Check if a string is palindrome
 ************************************************************************************************/
void removeSpaces(char *str)
{
    char *cur = str;
    char *start = str;
    while(*cur)
    {
        if(*cur != ' ')
        {
            *start++ = *cur;
        }
        cur++;
    }
    *start = '\0';
}

/* ************************************************************************************************
 * Searching for Patterns (Naive solution)
 *      Searching all occurrences of pattern(string) in target(string)
 *      Similar to strstr
 *************************************************************************************************/
bool searchPattern(char* target, char* pattern)
{
    int M = strlen(target);
    int N = strlen(pattern);
    int j = 0, i = 0;

    if(N > M)
    {
        return false;
    }
    for(i = 0 ; i <= M - N ; i++ )
    {
        for(j = 0 ; j < N ; j++)
        {
            if(target[j+i] != pattern[j])
            {
                break;
            }
        }
        if(j == N)
        {
            cout << "Pattern matched at index : " << i << " to " << i+j-1 << endl;
            break;
        }
    }
}

/* ************************************************************************************************
 * Optimized
 * assumption : pattern has all unique characters
 ************************************************************************************************/
bool searchPattern1(char* target, char* pattern)
{
    int m = strlen(target);
    int n = strlen(pattern);
    int j = 0,i = 0;
    if(n > m)
    {
        return false;
    }

    while(i<=m)
    {
        for(j = 0 ; j < n ; j++)
        {
            if(target[j+i] != pattern[j])
            {
                break;
            }
        }
        if(j == n)
        {
            cout << "Pattern matched at index : " << i << " to " << i+j-1 << endl;
            i = i + n;
        }
        else if(j == 0)
        {
            i += 1;
        }
        else if( j > 0)
        {
            i = i + j;
        }
    }
}

/* ************************************************************************************************
 * Compress a string
 ************************************************************************************************/
int compress(vector<char>& chars)
{
    int curIndex = 0, writeIndex = 0;
    int readIndex = 0;
    for (int i=0 ; i < chars.size() ; ++i )
    {
        if (i+1 == chars.size() || chars[i+1] != chars[i] )
        {
            chars[writeIndex++] = chars[readIndex];
            if (i > readIndex)
            {
                string s = to_string(i - readIndex + 1);
                for (char c : s)
                {
                    chars[writeIndex++] = c;
                }
            }
            readIndex = i+1;
        }
    }
    return writeIndex;
}

/* ************************************************************************************************
 * lps
 *      Returns the length of the longest palindromic subsequence in string
 *************************************************************************************************/
int lps(char *str)
{
    int n = strlen(str);
    int i, j, cl;
    int L[n][n]={};  // Create a table to store results of subproblems

    // Strings of length 1 are palindrome of lentgh 1
    for (i = 0; i < n; i++)
        L[i][i] = 1;

    // cl is length of substring
    for (cl=2; cl<=n; cl++)
    {
        for (i=0; i<n-cl+1; i++)
        {
            j = i+cl-1;
            if (str[i] == str[j] && cl == 2)
                L[i][j] = 2;
            else if (str[i] == str[j])
                L[i][j] = L[i+1][j-1] + 2;
            else
                L[i][j] = max(L[i][j-1], L[i+1][j]);
        }
    }
    cout << "lps is " << L[0][n-1] << endl;
    return L[0][n-1];
}
/*
**************************************************************************************************
 * stringMain
 ************************************************************************************************/
void stringMain()
{
    cout << "Hello from stringMain" << endl;
    char str[] = "BBBAABACBBAA";
    char pattern[] = "ABACB";

    lps(str);

    searchPattern(str,pattern);
    searchPattern1(str,pattern);

    char stri[] = "This is a test";
    maxOccuringcharacter(stri);
    removeSpaces(stri);
    cout << "After removing spaes " << stri << endl;
    vector<char> v= {'a','a','b','c','d','d','d','a','a'};

    compress(v);

    return;
}