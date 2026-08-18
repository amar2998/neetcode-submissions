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
    void traverse(TreeNode* root,vector<vector<int>>& ans){
        if(root==NULL){
            return;
        }
        else{
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty()){
                vector<int> subAns;
                int n=q.size();
                for(int i=0;i<n;i++){
                    TreeNode* front=q.front();
                    q.pop();
                    subAns.push_back(front->val);

                    if(front->left){
                        q.push(front->left);
                    }
                    if(front->right){
                        q.push(front->right);
                    }
                }
                ans.push_back(subAns);
                
            }

            return;
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        traverse(root,ans);
        return ans;
    }
};
