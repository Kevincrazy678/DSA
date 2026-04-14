#include<bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node *left;
    Node *right;
    int height;
};

int getHeight(Node* n) {
    if (n == NULL) return 0;
    return n->height;
}

Node* newNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

int getBalance(Node* n) {
    if (n == NULL) return 0;
    return getHeight(n->left) - getHeight(n->right);
}

Node* insert(Node* node, int key) {
    if (node == NULL) return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;
 
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void saveInorder(Node* root, ofstream& outFile) {
    if (root != NULL) {
        saveInorder(root->left, outFile);
        outFile << root->key << " ";
        saveInorder(root->right, outFile);
    }
}

int main() {
    Node* root = NULL;

    ifstream inFile("input.txt");
    if (!inFile) {
        cerr << "Cannot open file input.txt!" << endl;
        return 1;
    }

    int val;
    while (inFile >> val) {
        root = insert(root, val);
    }
    inFile.close();

    ofstream outFile("output.txt");
    if (!outFile) {
        cerr << "Cannot open file output.txt!" << endl;
        return 1;
    }

    saveInorder(root, outFile);
    outFile.close();

    cout << "Done" << endl;

    return 0;
}