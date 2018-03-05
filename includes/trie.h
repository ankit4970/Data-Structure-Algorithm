//
// Created by ankit on 1/19/2018.
//

#ifndef INTERVIEW_TRIE_H
#define INTERVIEW_TRIE_H

#include "common.h"

const int ALPHABET_SIZE = 26;
// trie node
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    // isEndOfWord is true if the node represents
    // end of a word
    bool isEndOfWord;
};


class TrieClass{
    void insert(struct TrieNode *root, string key);
    bool search(struct TrieNode *root, string key);
    struct TrieNode *getNode(void);
public:
    void trieMain();
};
#endif //INTERVIEW_TRIE_H
