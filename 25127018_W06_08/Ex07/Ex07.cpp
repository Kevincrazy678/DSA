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
    TreeNode* build(vector<int>& nums, int left, int right){
        /*
        we are using a recursive approach to build the binary search tree from the sorted array by 
        finding the middle element of the array and making it the root of the tree, and then recursively 
        building the left subtree from the left half of the array and the right subtree from the right half of the array
        */
        if(left > right) return nullptr;
        int mid = left + (right - left)/2;
        /*
        we are creating a new node with the value of the middle element of the array and we are setting the left child of the node 
        to the result of recursively building the left subtree from the left half of the array and the right child of the node 
        to the result of recursively building the right subtree from the right half of the array, and then we are returning 
        the node as the root of the tree
        */
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = build(nums, left, mid-1);
        root->right = build(nums, mid+1, right);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        //time complexity: O(n) where n is the number of elements in the array
        //space complexity: O(n) where n is the number of elements in the array
        int left = 0, right = nums.size()-1;
        return build(nums, left, right);
    }
};

/*
test case 1: not normally arranged
[-10,-3,0,5,9]
Ans: [0,-10,5,null,-3,null,9]

test case 2: odd number of nodes in the tree
[1,3]
Ans: [1,null,3]

test case 3: only one node in the tree
[[1]]
Ans: [[1]]
*/