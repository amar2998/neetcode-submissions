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
    TreeNode* build(vector<int>& preorder,vector<int>& inorder,unordered_map<int,int>& inorderMap,int& preorderIndex,int inorderstart,int inorderEnd,int size){
        if(preorderIndex >= size || inorderstart >  inorderEnd){
            return NULL;
        }
        int ele=preorder[preorderIndex++];
        int p=inorderMap[ele];
        TreeNode* root=new TreeNode(ele);
        root->left=build(preorder,inorder,inorderMap,preorderIndex,inorderstart,p-1,size);
        root->right=build(preorder,inorder,inorderMap,preorderIndex,p+1,inorderEnd,size);
        return root;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> inorderedMap;
        for(int i=0;i<inorder.size();i++){
            inorderedMap[inorder[i]]=i;
        }
        int n=inorder.size();
        int preorderedIndex=0;
        TreeNode* ans=build(preorder,inorder,inorderedMap,preorderedIndex,0,n-1,n);
        return ans;
    }
};
