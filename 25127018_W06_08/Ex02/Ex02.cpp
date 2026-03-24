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
  	
  	void preOrder(Node *root) {
		
      	if( root == NULL )
          	return;
      
      	std::cout << root->data << " ";
      	
      	preOrder(root->left);
      	preOrder(root->right);
    }

/*
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

    Node * insert(Node * root, int data) {
        //Time Complexity: O(h) where h is the height of the tree
        //Space Complexity: O(1)
        if(root == nullptr){
            return new Node(data);
        }
        //Iteratively traverse the tree to find the correct position for the new node
        Node* cur = root;
        while(1){
            //If the new data is greater than the current node's data, go to the right subtree
            if(cur->data < data){
                //If the right child is null, insert the new node here
                if(cur->right == nullptr){
                    cur->right = new Node(data);
                    break;
                }
                cur = cur->right;
            }
            //If the new data is less than or equal to the current node's data, go to the left subtree
            else{
                //If the left child is null, insert the new node here
                if(cur->left == nullptr){
                    cur->left = new Node(data);
                    break;
                }
                cur = cur->left;
            }
        }
        return root;
    }

};

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
Test case 1: The value has already been sorted in the tree
Input: 
6
4 2 3 1 7 6
Output:
4 2 1 3 7 6 

Test case 2: The value is less than the root node
Input: 
11
20 18 17 15 14 13 12 10 9 7 3
Output:
20 18 17 15 14 13 12 10 9 7 3 

Test case 3: The value is greater than the root node
Input:
10 
12 15 14 16 18 17 20 19 21
Output:
12 15 14 16 18 17 20 19 21

*/