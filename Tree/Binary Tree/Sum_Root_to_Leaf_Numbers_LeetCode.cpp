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
    int ans=0, makenum=0;
    
    int sumNumbers(TreeNode* root) {
        if(root==NULL) return ans;
        
        makenum=makenum*10+root->val;
        
        if(root->left==NULL&&root->right==NULL){
            ans+=makenum;
            return ans;
        }
        
        sumNumbers(root->left);
        if(root->left!=NULL) makenum/=10;
        sumNumbers(root->right);
        if(root->right!=NULL) makenum/=10;
        
        return ans;
    }
};
