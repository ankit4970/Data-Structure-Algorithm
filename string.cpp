//
// Created by ankit on 9/20/2017.
//
#include "common.h"
#include <cstring>
#include <chrono>

#define max(a,b) (a > b ? a : b)
#define min(a,b) (a < b ? a : b)
#if 0
bool isSubsequence(char* s, char* t) {

    while (*t)
        s = s + (*s == *t++);
    return !*s;
}
#endif
/*************************************************************************************************
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

/*************************************************************************************************
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

/*************************************************************************************************
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
            std::cout <<"%s is Not Palindrome\n"<<str;
            return;
        }
    }
    std::cout << "%s is palindrome\n"<< str << std::endl;
}

void maxOccuringcharacter(char *str)
{
    char map[256]= {};
    for (int i=0 ; i < strlen(str) ; i++)
    {
        map[str[i]]++;
    }
    int max = 0;
    char result = '\0';
    for (int i=0 ; i < strlen(str) ; i++)
    {
        if(max < map[str[i]])
            max =   map[str[i]];
        result = str[i];
    }
    printf("answer is %c\n",result);
}

void removeSpaces(char *str)
{
    int i = 0, count  = 0;

    while(*(str+i))
    {
        if(*(str+i) != ' ')
        {
            *(str+count) = *(str+i);
            count++;
        }
        i++;
    }
    *(str+count) = '\0';
}

// Returns the length of the longest palindromic subsequence in seq
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

    return L[0][n-1];
}
/*
 * ************************************************************************************************
 * Searching for Patterns (Naive solution)
 *      Searching all occurrences of pattern(string) in target(string)
 ***********************************************************************************************
 **/
bool searchPattern(char* target, char* pattern)
{
    int m = strlen(target);
    int n = strlen(pattern);
    int j = 0,i = 0;
    if(n > m)
    {
        return false;
    }
    for(i = 0 ; i <= m - n ; i++ )
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
        }
    }
}
/* Optimized
 * assumption : pattern has all unique characters
*/
bool searchPattern1(char* target, char* pattern)
{
    int m = strlen(target);
    int n = strlen(pattern);
    int j = 0,i = 0;
    if(n > m)
    {
        return false;
    }
    //for(i = 0 ; i <= m - n ; i++ )
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

void stringMain()
{
    std::cout << "Hello from stringMain" << std::endl;

    char str[] = "BBBAABACBBAA";
    char pattern[] = "ABACB";
    //std::cout << "lps is " << lps(str) << std::endl;

    searchPattern(str,pattern);


    searchPattern1(str,pattern);

    return;
}