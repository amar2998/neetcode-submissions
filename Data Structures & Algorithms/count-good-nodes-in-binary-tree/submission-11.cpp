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
    void traverse(TreeNode* root,int maxVal,int& counter){
        if(root==NULL){
            return;
        }
        if(root->val >= maxVal){
            counter++;
            maxVal=root->val;
        }
        traverse(root->left,maxVal,counter);
        traverse(root->right,maxVal,counter);
        
    }
    
    int goodNodes(TreeNode* root) {
        
        int counter=0;
        int maxVal=INT_MIN;
        traverse(root,maxVal,counter);
        return counter;
    }
};
