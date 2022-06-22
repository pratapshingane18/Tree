#include"bits/stdc++.h"

using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;

    }
};

int CalcHeight(Node* root){
    if(root == NULL){
        return 0;
    }

    
    return max(CalcHeight(root->left),CalcHeight(root->right)) +1;
}

int CalcDiameter(Node* root){
    if(root == NULL){
        return 0;
    }

    int lheight = CalcHeight(root->left);
    int rheight = CalcHeight(root->right);

    int currDiameter = lheight + rheight +1;

    int ldiameter = CalcDiameter(root->left);
    int rdiameter = CalcDiameter(root->right);

    return max(currDiameter, max(ldiameter,rdiameter));

}

int main(){

    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    
    cout<<CalcDiameter(root);
    return 0;
}