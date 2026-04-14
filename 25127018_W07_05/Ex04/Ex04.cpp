/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::kthsmallest(TreeNode* A, int B) {
    //time complexity: O(n) with n is the number of nodes in the tree, in the worst case, we need to check all the nodes in the tree
    //space complexity: O(h) with h is the height of the tree, in the worst case, we need to check all the nodes in one level of the tree
    stack<TreeNode*>st;
    TreeNode* cur = A;
    // we can use in-order traversal to get the nodes in sorted order, and we can stop when we find the kth smallest node
    while(cur != nullptr || !st.empty()){
        // we need to go to the leftmost node first, and then we can check the value of the node, if it is the kth smallest node, we can return it, otherwise, we can go to the right subtree
        while(cur != nullptr){
            st.push(cur);
            cur = cur->left;
        }
        // when we pop the node from the stack, we can check if it is the kth smallest node, if it is, we can return it, otherwise, we can go to the right subtree
        cur = st.top();  st.pop();
        B--;
        if(B==0)return cur->val;
        cur = cur->right;
    }
    // if we cannot find the kth smallest node, we can return -1
    return -1;
}
/*
Test case 1: the tree has 5 nodes, and we want to find the 3rd smallest node
Input: A = [5,3,6,2,4], B = 3
Answer: 4
Test case 2: the tree has 3 nodes, and we want to find the 1st smallest node
Input: A = [3,1,4], B = 1
Answer: 1
Test case 3: the tree has 3 nodes, and we want to find the 2nd smallest node
Input: A = [3,1,4], B = 2
Answer: 3
*/

