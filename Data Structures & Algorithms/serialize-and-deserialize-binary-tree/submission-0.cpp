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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        string s;

        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();

            if(front==NULL){
                s.append("#,");
                continue;
            }
            s.append(to_string(front->val)+",");
            q.push(front->left);
            q.push(front->right);
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<TreeNode*>q;

        stringstream ss(data);
        string s;
        getline(ss,s,',');
        if(s=="#") return NULL;
        TreeNode* root = new TreeNode(stoi(s));
        q.push(root);

        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            getline(ss,s,',');
            if(s=="#"){
                front->left = NULL;
            } else {
                TreeNode* leftNode = new TreeNode(stoi(s));
                front->left = leftNode;
                q.push(leftNode);
            }
            getline(ss,s,',');
            if(s=="#"){
                front->right = NULL;
            } else {
                TreeNode* rightNode = new TreeNode(stoi(s));
                front->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};
