/* **************************************************************************************
 * string.cpp
 *
 *  Created by ankit on 9/20/2017
 *      Author: ankit
 ***************************************************************************************/


#include "mystring.h"

/* **************************************************************************************
 * Check if target string is subsequence of source string
   ex. input : source : aabcbccdddeee
               target : abcde
      output : true
****************************************************************************************/
bool stringClass::isSubsequence(char* source, char* target)
{
    while (*target)
    {
        source = source + (*source == *target++);
    }
    return !*source;
}

/* **************************************************************************************
 * Reverses a given string
   ex. input : string
       output : gnirts
****************************************************************************************/
void stringClass::reverseString(char *begin, char *end)
{
    char temp;
    while (begin < end)
    {
        temp = *begin;
        *begin++ = *end;
        *end-- = temp;
    }
}

/* **************************************************************************************
 * Reverses words in a given string
   ex. input  : this is a string
       output : string a is this
 ***************************************************************************************/
void stringClass::stringReverseWords(char *string)
{
    char *begin = string;
    char *end = string;

    if (string)
    {
        while (*end)
        {
            end++;
            if (*end == '\0')
            {
                reverseString(begin, end-1);
            }
            else if (*end == ' ')
            {
                reverseString(begin, end-1);
                begin = end+1;
            }
        }
        reverseString(string, end-1);
    }
}

/* **************************************************************************************
 * Check if a string is palindrome
   i.e. input : aaddddaa output : is palindrome
       input : abcded   output : is not palindrome
 ***************************************************************************************/
void stringClass::isPalindrome(char str[])
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
 * maxOccuringcharacter
 *      Returns a character with maximum occurence
   i.e. input : aaddddaa output : is palindrome
       input : abcded   output : is not palindrome
 ************************************************************************************************/
char stringClass::maxOccuringcharacter(char *str)
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
    cout << "Maximum occuring character in \"" <<str<<"\" is : "<<result<<' ' <<maximum<<" times"<<endl;
    return result;
}

/* **************************************************************************************
 * removeSpaces
 *      Remove spaces from a given string
 ***************************************************************************************/
void stringClass::removeSpaces(char *str)
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



/* **************************************************************************************
 * removeSpaces
 *      Remove spaces from a given string
 ***************************************************************************************/
void stringClass::removeDuplicates(char* str)
{
    unsigned int readIndex = 0;
    unsigned int writeIndex = 0;
    char* stri = str;
    char Map[256] = {};
    int count = 0;

    while (stri[readIndex] != '\0')
    {
        if (stri[readIndex] == ' ')
        {
            count++;
        }
        if (Map[stri[readIndex]] <= 0+count)
        {
            stri[writeIndex] = stri[readIndex];
            Map[stri[readIndex]]++;
            readIndex++;
            writeIndex++;

        }
        else
        {
            readIndex++;
        }
    }
    stri[writeIndex] = '\0';
}

/* ************************************************************************************************
 * Searching for Patterns (Naive solution)
 *      Searching all occurrences of pattern(string) in target(string)
 *      Similar to strstr
 *************************************************************************************************/
bool stringClass::searchPattern(char* target, char* pattern)
{
    int M = strlen(target);
    int N = strlen(pattern);
    int j = 0, i = 0;

    if (N > M)
    {
        return false;
    }
    for (i = 0 ; i <= M - N ; ++i )
    {
        for (j = 0 ; j < N ; ++j)
        {
            if (target[j+i] != pattern[j])
            {
                break;
            }
        }
        if (j == N)
        {
            cout << "Pattern matched at index : " << i << " to " << i+j-1 << endl;
            break;
        }
    }
}

/* ************************************************************************************************
 * Optimized
 *      assumption : pattern has all unique characters
 ************************************************************************************************/
bool stringClass::searchPattern1(char* target, char* pattern)
{
    int m = strlen(target);
    int n = strlen(pattern);
    int j = 0,i = 0;
    if(n > m)
    {
        return false;
    }

    while (i <= m)
    {
        for (j = 0 ; j < n ; j++)
        {
            if (target[j+i] != pattern[j])
            {
                break;
            }
        }
        if (j == n)
        {
            cout << "Pattern matched at index : " << i << " to " << i+j-1 << endl;
            i = i + n;
        }
        else if (j == 0)
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
 * compressString
 *      Compress a string
 ************************************************************************************************/
int stringClass::compressString(vector<char>& chars)
{
    int writeIndex = 0;
    int readIndex = 0;

    for (int i = 0 ; i < chars.size() ; ++i )
    {
        if (i+1 == chars.size() || chars[i] != chars[i+1])
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


/* **************************************************************************************
 * subSequenceTag
 *      Pre-Order traversal of Binary Tree
 *      ex:  //{"in","the","spain"};
 *      {"the","spain","that","the","rain","in","spain","stays","forecast","in","the"};
 ***************************************************************************************/
char* stringClass::compress(char* chars)
{
    int writeIndex = 0;
    int readIndex = 0;
    int length = strlen(chars);

    char *newString = (char*)malloc(2*length-1);

    for (int i=0 ; i < length-1 ; ++i )
    {
        if (i+1 == length || chars[i+1] != chars[i] )
        {
            newString[writeIndex++] = chars[readIndex];
            string s = to_string(i - readIndex + 1);
            for (char c : s)
            {
                newString[writeIndex++] = c;
            }
            readIndex = i+1;
        }
    }

    newString[writeIndex] = '\0';
    return newString;
}

/* ************************************************************************************************
 * longestPalindromeSubsequence
 *      Returns the length of the longest palindromic subsequence in string
 *************************************************************************************************/
uint32_t stringClass::longestPalindromeSubsequence(string str)
{
    vector<vector<int>> table(str.length()+1,vector<int>(str.length(),0));
    int n = str.length();

    // Strings of length 1 are palindrome of lentgh 1
    for (int i = 0; i < n ; ++i)
    {
        table[i][i] = 1;
    }

    for (int length = 2 ; length <= n ; ++length)
    {
        for (int i = 0 ; i < n-length+1; ++i)
        {
            int j = i+length-1;
            if (str[i] == str[j] && length == 2)
            {
                table[i][j] = 2;
            }
            else if (str[i] == str[j])
            {
                table[i][j] = table[i + 1][j - 1] + 2;
            }
            else
            {
                table[i][j] = max(table[i][j - 1], table[i + 1][j]);
            }
        }
    }
    cout << "lps is " << table[0][n-1] << endl;
    return table[0][n-1];
}

unordered_map<string, string> Map;
/* ************************************************************************************************
 * longestPalindromeSubstring
 *      Returns the length of the longest palindromic substring
 *************************************************************************************************/
string stringClass::mostRecentAnagram(std::string token)
{
    string temp = token;
    sort(token.begin(), token.end());
    string res;
    if(Map.find(token) != Map.end())
    {
        res = Map[token];
        Map[token] = temp;
    }
    else
    {
        Map[token] = temp;
        res = temp;
    }
    return res;
}

/* ************************************************************************************************
 * longestPalindromeSubstring
 *      Returns the length of the longest palindromic substring
 *************************************************************************************************/
string stringClass::longestPalindromeSubstring(std::string s)
{
    if (s.empty())
        return "";

    if (s.size() == 1)
        return s;

    int min_start = 0, max_len = 1;
    for (int i = 0; i < s.size();)
    {
        if (s.size() - i <= max_len / 2)
            break;
        int j = i, k = i;
        while (k < s.size()-1 && s[k+1] == s[k])
            ++k; // Skip duplicate characters.

        i = k+1;

        while (k < s.size()-1 && j > 0 && s[k + 1] == s[j - 1])
        {
            ++k;
            --j;
        } // Expand.

        int new_len = k - j + 1;
        if (new_len > max_len)
        {
            min_start = j;
            max_len = new_len;
        }
    }
    return s.substr(min_start, max_len);
}


/* **************************************************************************************
 * subSequenceTag
 *      Pre-Order traversal of Binary Tree
 *      ex:  //{"in","the","spain"};
 *      {"the","spain","that","the","rain","in","spain","stays","forecast","in","the"};
 ***************************************************************************************/
void stringClass::wordBreak()
{

}

/* **************************************************************************************
 * subSequenceTag
 *      Pre-Order traversal of Binary Tree
 *      ex:  //{"in","the","spain"};
 *      {"the","spain","that","the","rain","in","spain","stays","forecast","in","the"};
 ***************************************************************************************/
vector<int> stringClass::subSequenceTag(vector<string>& targetList,
                                        vector<string>& availableTagList)
{
    map<string,int> MapTarget;
    cout << targetList.size()<<endl;
    cout << availableTagList.size() <<endl;

    for (auto list : targetList)
    {
        MapTarget[list]++;
    }

    int startIndex = 0;
    int endIndex = 0;
    int count = targetList.size();
    map<string,bool> MapAvailable;
    int finalStart = 0;
    int finalEnd = 0;
    int diffMin = INT_MAX;
    vector<int> ret;

    while (endIndex < availableTagList.size())
    {
        auto it1 = MapTarget.find(availableTagList[endIndex]);
        if (it1 != MapTarget.end() && MapTarget[it1->first] > 0 )
        {
            MapTarget[it1->first]--;
            count--;
        }

        while (count == 0)
        {
            cout << "In while " << startIndex << ","<< endIndex <<endl;
            if (diffMin > (endIndex - startIndex))
            {
                diffMin = (endIndex - startIndex);
                finalStart = startIndex;
                finalEnd = endIndex;
            }

            auto it1 = MapTarget.find(availableTagList[startIndex]);
            if (it1 != MapTarget.end() )
            {
                MapTarget[it1->first]++;
                count++;
            }
            startIndex++;
        }
        endIndex++;
    }

    cout << "Final Start index is : " << finalStart << " Final End Index : " << finalEnd << endl;
}

#if 0
vector<int> stringClass::subSequenceTagNew(vector<std::string>& targetList, vector<std::string>& availableTagList)
{
    map<string,bool> MapTarget;
    for (auto list : targetList)
    {
        MapTarget.insert(std::pair<string,bool>(list,true));
    }
    int diff = 0;
    int startIndex = 0;
    int endIndex = 0;
    int count = 0;
    map<string,bool> MapAvailable;
    int finalStart = 0;
    int finalEnd = 0;
    int diffMin = INT_MAX;
    vector<int> ret ;
    for(int i = 0 ; i < availableTagList.size() ; i++)
    {
        while(count !)
        {

        }
        auto it1 = MapTarget.find(availableTagList[j]);
        if (it1 != MapTarget.end())
        {
            auto it2 = MapAvailable.find(availableTagList[j]);
            if (it2 == MapAvailable.end())
            {
                MapAvailable.insert(std::pair<string,bool>(availableTagList[j], true));
                if (count == 0)
                {
                    startIndex = j;
                }
                if (count == 2)
                {
                    endIndex = j;
                }
                count++;
            }
        }


        MapAvailable.clear();
        if(count == 3)
        {
            if (diffMin > (endIndex - startIndex))
            {
                diffMin = (endIndex - startIndex);
                finalStart = startIndex;
                finalEnd = endIndex;
            }
        }
        count = 0;
        startIndex = 0;
        endIndex = 0;
    }
    ret.push_back(finalStart);
    ret.push_back(finalEnd);
    cout << "Final Start index is : " << finalStart << " Final End Index : " << finalEnd << endl;
}
#endif
/*
**************************************************************************************************
 * stringMain
 ************************************************************************************************/
void stringClass::stringMain()
{
    cout << "Hello from stringMain" << endl;
    char str[] = "BBBAABACBBAA";
    char* recv  = NULL;
    //char pattern[] = "ABACB";
    //lps(str);
    //searchPattern(str,pattern);
    //searchPattern1(str,pattern);

    //char stri[] = "This is a test";
    //maxOccuringcharacter(stri);
    //removeSpaces(stri);
    //cout << "After removing spaes " << stri << endl;
    //vector<char> v= {'a','a','b','c','d','d','d','a','a'};

    //recv = compress(str);
    //printf("%s\n",recv);
    //free(recv);
    //char stri[] = "abbdea cde aabb";
    //removeDuplicates(stri);
    //cout << stri << endl;

    //vector<string> targetList ={"in","the","spain"};
    //vector<string> availableTagList = {"the","spain","that","the","rain","in","spain","stays","forecast","in","the"};
    //subSequenceTag(targetList, availableTagList);

    cout << mostRecentAnagram("abc") << endl;
    cout << mostRecentAnagram("def") << endl;
    cout << mostRecentAnagram("ghi") << endl;
    cout << mostRecentAnagram("jkl") << endl;
    cout << mostRecentAnagram("cba") << endl;
    return;
}