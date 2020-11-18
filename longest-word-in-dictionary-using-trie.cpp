
#include <bits/stdc++.h>

using namespace std;

#define ALPHABET_SIZE 26
#define FIRST_ALPHABET 'a'

struct TrieNode{
    struct TrieNode* children[ALPHABET_SIZE];
    bool is_leaf;
    TrieNode(){
        for(int i=0;i<ALPHABET_SIZE;i++){
            children[i] = NULL;
        }
        is_leaf = false;
    }

};

void insert(struct TrieNode* root, string s){
    int n = s.size();
    TrieNode* parser = root;
    for(int i=0;i<n;i++){
        if(parser->children[s[i]-FIRST_ALPHABET] == NULL){
            parser->children[s[i]-FIRST_ALPHABET] = new TrieNode();
        }
        parser = parser->children[s[i]-FIRST_ALPHABET];
    }
    parser->is_leaf = true;
}

string compute(TrieNode* root){
    if(root == NULL){
        return "";
    }
    string ans = "";
    for(int i=0;i<ALPHABET_SIZE;i++){
        string x = "";
        if(root->children[i] && root->children[i]->is_leaf){
            string c(1, FIRST_ALPHABET+i);
            x = c+compute(root->children[i]);
        }

        if(x.size() > ans.size()){
            ans = x;
        }
    }
    return ans;
}





int main() {

    vector<string> words;
    words.push_back("d");
    words.push_back("di");
    words.push_back("dil");
    words.push_back("dili");
    words.push_back("diliy");
    words.push_back("dilie");
    words.push_back("banana");

    TrieNode* root = new TrieNode();
    for(int i=0;i<words.size();i++){
        insert(root, words[i]);
    }

    string ans = compute(root);
    cout<<ans;
    return 0;
}
