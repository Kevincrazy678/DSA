/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    //we are using a dummy node to store the previous node in the in-order traversal and we are using a pointer to store the current node in the in-order traversal, which is the next node in the increasing order search tree, and we are updating the previous node to the current node after we set the left child of the current node to null and the right child to the next node in the in-order traversal
    TreeNode* ptr = new TreeNode(-1);
    //we are using a pointer to store the previous node in the in-order traversal and we are using a pointer to store the current node in the in-order traversal, which is the next node in the increasing order search tree, and we are updating the previous node to the current node after we set the left child of the current node to null and the right child to the next node in the in-order traversal
    TreeNode* prev = ptr;
    void inorder(TreeNode* root){
        if(root == nullptr) return;
        //we are using in-order traversal to traverse the tree and we are rearranging the nodes of the tree in increasing order by setting the left child of each node to null and the right child to the next node in the in-order traversal
        inorder(root->left);
        //we are setting the left child of the current node to null and the right child to the next node in the in-order traversal, which is the current node itself, and then we are updating the previous node to the current node
        root->left = nullptr;
        prev->right = root;
        prev = root;
        //then we are traversing the right subtree
        inorder(root->right);
    } 
public:
    TreeNode* increasingBST(TreeNode* root) {
        //time complexity: O(n) where n is the number of nodes in the tree
        //space complexity: O(h) where h is the height of the tree
        inorder(root);
        return ptr->right;
    }
};

/*
test case 1: not normally arranged
[5,3,6,2,4,null,8,1,null,null,null,7,9]
Ans: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

test case 2: odd number of nodes in the tree
[5,1,7]
Ans: [1,null,5,null,7]

test case 3: only one node in the tree
[[1]]
Ans: [[1]]
*/