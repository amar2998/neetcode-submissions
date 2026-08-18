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
public:
    int diameter(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        
        return 1+max(diameter(root->left),diameter(root->right)); 
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        else{
            int leftMax=diameterOfBinaryTree(root->left);
            int rightMax=diameterOfBinaryTree(root->right);
            int curr=diameter(root->left) + diameter(root->right);

            return max(curr,max(leftMax,rightMax));

        }
    }
};
