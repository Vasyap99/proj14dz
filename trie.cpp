#include <iostream>
#include "Trie.h"

using namespace std; 


TrieNode *getNewNode()
{
    struct TrieNode *pNode =  new TrieNode;

    pNode->isEndOfWord = false; 

    for (int i = 0; i < ALPHABET_SIZE; i++) 
        pNode->children[i] = nullptr;

    return pNode;
} 


void insert(TrieNode* root, string key) 
{

    if(key==""){
        root->isEndOfWord = true; 
    } 
    for(int i=0;i<key.length();i++){
        int c=key[i]-'a';
        if(c>=ALPHABET_SIZE) return;        
        if(root->children[c]==nullptr){//+el
            TrieNode *n = getNewNode(); 
            root->children[c]=n;
            root=n;
            if(i==key.length()-1){
                n->isEndOfWord = true; 
            }
        }else{
            root=root->children[c];
            if(i==key.length()-1){
                root->isEndOfWord = true; 
            }
        }
    }
}
