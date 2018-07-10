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

#include <iostream>
#include <string>
#include <chrono>
#include <map>
#include <unordered_map>
#include <vector>
#include <cstring>
#include <climits>
#include <algorithm>

using namespace std;

class stringClass
{
    vector<int> subSequenceTag(vector<string>& targetList, vector<string>& availableTagList);
    vector<int> subSequenceTagNew(vector<std::string>& targetList, vector<std::string>& availableTagList);

    uint32_t longestPalindromeSubsequence(string sequence);
    string longestPalindromeSubstring(string sequence);

    int lps(char *str);
    char* compress(char* chars);
    int compressString(vector<char>& chars);
    bool searchPattern1(char* target, char* pattern);
    bool searchPattern(char* target, char* pattern);
    void removeSpaces(char *str);
    void removeDuplicates(char* str);
    char maxOccuringcharacter(char *str);
    void isPalindrome(char str[]);
    void stringReverseWords(char *string);
    void reverseString(char *begin, char *end);
    bool isSubsequence(char* s, char* t);
    void wordBreak();
    string mostRecentAnagram(string token);
public:
    void stringMain();
};
#endif //INTERVIEW_STRING_H

#endif //INTERVIEW_MYSTRING_H
