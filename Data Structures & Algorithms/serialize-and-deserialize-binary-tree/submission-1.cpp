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
    void dfsSerialize(TreeNode* root, string &s) {
        if(!root) {
            s+="#,"; return;
        }
        s+=to_string(root->val)+',';
        dfsSerialize(root->left,s);
        dfsSerialize(root->right,s);
    }
    TreeNode* dfsDeserialize(stringstream &ss, string token) {
        if(token=="#") return nullptr;
        // node
        TreeNode* node = new TreeNode(stoi(token));
        getline(ss,token,',');
        node->left=dfsDeserialize(ss, token);
        getline(ss,token,',');
        node->right=dfsDeserialize(ss,token);
        return node;
    }

   public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str="";
        dfsSerialize(root,str);
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string token;
        getline(ss,token,',');
        return dfsDeserialize(ss,token);
    }
};
