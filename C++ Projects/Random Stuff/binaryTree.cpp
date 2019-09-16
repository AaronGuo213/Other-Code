#include <iostream>
using namespace std;

struct node {

    int data;
    node* left;
    node* right;

};

struct node* newNode(int idata) {

    node* node = new struct node;
    node -> data = idata;
    node -> left = NULL;
    node -> right = NULL;
    return node;

}

int main() {

    node* root = newNode(10);
    root -> left = newNode(5);
    root -> right = newNode(15);
    cout << " " << root->data << endl << root->left->data << "  " << root->right->data;

}