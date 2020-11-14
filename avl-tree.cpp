

#include <iostream>
#include <bits/stdc++.h>

using namespace  std;

struct TreeNode{
    int data;
    int height;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        data = val;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

int height(TreeNode* root){
    if(root == NULL){
        return 0;
    }else{
        return root->height;
    }
}

TreeNode* right_rotate(TreeNode* x){
    TreeNode* y = x->left;
    TreeNode* t2 = y->right;

    y->right = x;
    x->left = t2;

    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    return y;
}

TreeNode* left_rotate(TreeNode* y){
    TreeNode* x = y->right;
    TreeNode* t2 = x->left;

    x->left = y;
    y->right = t2;

    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    return x;
}

int balance_factor(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    return height(root->left) - height(root->right);
}

TreeNode* insert(TreeNode* root, int x){
    if(root == NULL){
        TreeNode* new_node = new TreeNode(x);
        return new_node;
    }

    //Do a regular BST insertion
    if(x < root->data){
        root->left = insert(root->left, x);
    }else if(x > root->data){
        root->right = insert(root->right, x);
    }else{
        //This case is to handle the duplicate entries
        //If there are any duplicate entries we ignore them
        return root;
    }

    //Now you balance the nodes
    root->height = max(height(root->left), height(root->right))+1;

    int balance = balance_factor(root);

    if(balance > 1 && x < root->left->data){
        return right_rotate(root);
    }
    if(balance < -1 && x > root->right->data){
        return left_rotate(root);
    }
    if(balance > 1 && x > root->left->data){
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }
    if(balance < -1 && x < root->right->data){
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }

    return root;
}

void inorder(TreeNode* root, vector<int> &v){
    if(root == NULL){
        return;
    }else{
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }
}

int main(){
    TreeNode* root= NULL;

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        root = insert(root, x);
    }
    vector<int> v;
    inorder(root, v);
    int s = v.size();
    for(int i=0;i<s;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    return 0;
}
