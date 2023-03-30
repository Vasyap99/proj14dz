#pragma once
#include <iostream>
#include <string>

using namespace std;

#define ALPHABET_SIZE 26

struct TrieNode
{
   struct TrieNode *children[ALPHABET_SIZE];
   bool isEndOfWord;
   ~TrieNode(){
   		for(int i=0;i<ALPHABET_SIZE;i++) if(children[i]!=nullptr){
   			delete children[i];
		}
		cout << "~" << endl;
   }
};

TrieNode *getNewNode();

void insert(TrieNode* root, string key);
