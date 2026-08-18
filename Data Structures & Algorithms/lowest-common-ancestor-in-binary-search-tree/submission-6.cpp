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
    bool findTarget(TreeNode* root,TreeNode* target,vector<TreeNode*>& ans){
        if(root==NULL){
            return false;
        }
        ans.push_back(root);
        if(root->val ==target->val){
            return true;
        }
        if(findTarget(root->left,target,ans) || findTarget(root->right,target,ans)){
            return true;
        }
        else{
            ans.pop_back();
            return false;
        }

    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> parr;
        findTarget(root,p,parr);
        vector<TreeNode*> qarr;
        findTarget(root,q,qarr);
        unordered_map<TreeNode*,int> pMap;
        for(int i=0;i<parr.size();i++){
            pMap.insert({parr[i],i});
        }
        for(int j=qarr.size()-1;j>=0;j--){
            if(pMap.find(qarr[j]) != pMap.end()){
                return qarr[j];
            }
        }

        return NULL;
    }
};
