#include <bits/stdc++.h>

using namespace  std;

#define ALPHABET_SIZE 26
#define FIRST_ALPHABET 'a'

struct TrieNode{
    struct TrieNode *children[ALPHABET_SIZE];
    bool is_leaf;

    TrieNode(){
        is_leaf = false;
        for(int i=0;i<ALPHABET_SIZE;i++){
            children[i] = NULL;
        }
    }
};

void insert(TrieNode* root, string s){
    int n = s.size();
    TrieNode* parser = root;
    for(int i=0;i<n;i++){
        if(parser->children[s[i]-FIRST_ALPHABET]){
            parser = parser->children[s[i]-FIRST_ALPHABET];
        }else{
            parser->children[s[i]-FIRST_ALPHABET] = new TrieNode();
            if(i == n-1){
                parser->children[s[i]-FIRST_ALPHABET]->is_leaf = true;
            }
            parser = parser->children[s[i]-FIRST_ALPHABET];
        }
    }
}

bool find_in_trie(TrieNode* root, string s){
    int n = s.size();
    TrieNode* parser = root;
    for(int i=0;i<n;i++){
        if(parser->children[s[i]-FIRST_ALPHABET]){
            if(i == n-1 && parser->children[s[i]-FIRST_ALPHABET]->is_leaf == true){
                return true;
            }
            parser = parser->children[s[i]-FIRST_ALPHABET];
        }else{
            return false;
        }
    }
    return false;
}


int main(){
    struct TrieNode *root = new TrieNode();

    insert(root, "dilip");
    insert(root, "dirip");
    insert(root, "dilil");
    insert(root, "dirir");
    cout<<find_in_trie(root, "diril");

    return 0;
}
