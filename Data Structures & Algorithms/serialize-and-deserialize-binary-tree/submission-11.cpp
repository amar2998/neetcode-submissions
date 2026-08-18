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

class Codec {
public:
    void preorder(TreeNode* root, string& ans) {
        if (root == nullptr) {
            ans += "N,";
            return;
        }

        ans += to_string(root->val) + ",";
        preorder(root->left, ans);
        preorder(root->right, ans);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        preorder(root,ans);
        
        return ans;
    }
    TreeNode* build(vector<string>& arr, int& i) {

    if (arr[i] == "N") {
        i++;
        return nullptr;
    }

    TreeNode* node = new TreeNode(stoi(arr[i]));
    i++;

    node->left = build(arr, i);
    node->right = build(arr, i);

    return node;
}
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> arr;
        stringstream ss(data);
        string temp;

        while (getline(ss, temp, ',')) {
            arr.push_back(temp);
        }
        int index=0;
        TreeNode* root=build(arr,index);
        return root;
    }
};
