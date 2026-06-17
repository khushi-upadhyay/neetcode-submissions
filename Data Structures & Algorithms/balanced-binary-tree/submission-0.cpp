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
    int maxDepth(TreeNode* root){
        if(!root) return 0;
        int leftDepth =  maxDepth(root->left);
         // unbalanced left subtree
        if(leftDepth == -1) return -1;
        int rightDepth = maxDepth(root->right);
        // unbalanced right subtree
        if(rightDepth == -1) return -1; 
        // If the difference in heights is > 1, tree is unbalanced
        if(abs(leftDepth - rightDepth) > 1) return -1; 
        //return height of this subtree
        return max(leftDepth, rightDepth) +1;
    }
public:
    bool isBalanced(TreeNode* root) {
        return maxDepth(root) != -1;
        
    }
};