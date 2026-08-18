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
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return 1+max(height(root->left),height(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;
        }

        else{
            bool left=isBalanced(root->left);
            bool right=isBalanced(root->right);
            int currans=abs(height(root->left)-height(root->right));
            if( left && right && currans <=1){
                return true;
            }
            else{
                return false;
            }
        }
    }
};
