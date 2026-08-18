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

    bool isEqual(TreeNode* root,TreeNode* subRoot){
        if(root==NULL && subRoot==NULL){
            return true;
        }
        if((root!=NULL && subRoot!=NULL) && (root->val==subRoot->val) ){
            return isEqual(root->left,subRoot->left) && isEqual(root->right,subRoot->right);
        }
        else{
            return false;
        }
    } 
    TreeNode* find(TreeNode* root,TreeNode* subTree){
        
        if(root==NULL){
            return NULL;
        }
        if(root->val==subTree->val && isEqual(root,subTree)){
            return root;
        }
        else{
            TreeNode* leftRoot=find(root->left,subTree);
            if(leftRoot!=NULL){
                return leftRoot;
            }
            return  find(root->right,subTree);
            
        }
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return find(root,subRoot)!=NULL;
    }
};
