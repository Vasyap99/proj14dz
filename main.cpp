#include <iostream>
#include <vector>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#include "trie.h"

void obhod(TrieNode *root, string b, vector<string> &res){
	for(int i=0; i<ALPHABET_SIZE; i++) if(root->children[i]!=nullptr){
		obhod(root->children[i], b+(char)(i+'a'),res);
	}
	if(root->isEndOfWord){
		res.push_back(b);
	}
}

void get_strs(TrieNode *root, string &key, vector<string> &res){
	res.clear();
	//
	for(int i=0;i<key.length();i++){
        int c=key[i]-'a';
        if(c>=ALPHABET_SIZE) return;        
        if(root->children[c]==nullptr){//no such elem
			return;
        }else{
            root=root->children[c];
        }
    }
    //
    obhod(root, "", res);
}

int main(int argc, char** argv) {
	TrieNode *n=getNewNode();
	
	string s;
	vector<string> res;

    insert(n, "kookoko");
    insert(n, "kokoko");    
    insert(n, "kukukukuu");    
    insert(n, "kukkukukuu");        
    insert(n, "okookoko");    
    insert(n, "ok");   
	
	while(true){
		char c;
		cin >> c;
		if(c=='.') break;
		s+=c;
		get_strs(n, s, res);
		cout << "-----" << endl;
		for(auto i:res){
			cout << i << endl;
		}
		cout << "-----" << endl;
	}
	
	delete n;
	 
	return 0;
}
