#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/* you only have to complete the function given below.  
Node is defined as  

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    void preOrder(Node *root) {
        //time complexity: O(n) where n is the number of nodes in the tree
        //space complexity: O(h) where h is the height of the tree
        if(root == nullptr){
            return;
        }
        //we are using pre-order traversal to traverse the tree and print the value of the node, then the left subtree, and then the right subtree
        cout<<root->data<<" ";
        //, then the left subtree, and then the right subtree
        preOrder(root->left);
        preOrder(root->right);
    }

}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
	myTree.preOrder(root);
    return 0;
}

/*
test case 1: not normally arranged
Inp:
6
1 2 5 3 6 4
Ans: 1 2 3 5 4 6

test case 2: randomly arranged nodes
Inp:
15
1 14 3 7 4 5 15 6 13 10 11 2 12 8 9
Ans: 1 14 3 2 7 4 5 6 13 10 8 9 11 12 15

test case 3: only one node in the tree
Inp:
1
1 
Ans: 1 
*/