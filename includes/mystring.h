//
// Created by ankit on 1/22/2018.
//

#ifndef INTERVIEW_MYSTRING_H
#define INTERVIEW_MYSTRING_H
//
// Created by ankit on 1/22/2018.
//

#ifndef INTERVIEW_STRING_H
#define INTERVIEW_STRING_H

#include "common.h"
#include <chrono>
#include <map>
#include <unordered_map>
#include <string>
#include <vector>

class StringClass
{
    vector<int> subSequenceTag(vector<string>& targetList, vector<string>& availableTagList);
    vector<int> subSequenceTagNew(vector<std::string>& targetList, vector<std::string>& availableTagList);
    int longestPalindromeSubsequence(string str);
    string longestPalindromeSubstring(std::string s);
    int lps(char *str);
    char* compress(char* chars);
    int compress(vector<char>& chars);
    bool searchPattern1(char* target, char* pattern);
    bool searchPattern(char* target, char* pattern);
    void removeSpaces(char *str);
    void maxOccuringcharacter(char *str);
    void isPalindrome(char str[]);
    void stringReverseWords(char *string);
    void reverse(char *begin, char *end);
    bool isSubsequence(char* s, char* t);
public:
    void stringMain();
};
#endif //INTERVIEW_STRING_H

#endif //INTERVIEW_MYSTRING_H
