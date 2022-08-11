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

typedef long long int ll;
class Solution {
public:
        bool isBST(TreeNode* root,long long int  min,long long int max)
        {
            if(root==NULL)
            {
                return true;
            }
            if(root->val<min || root->val>max){
                return false;
            }
             bool check_BSTL=isBST(root->left,(ll)min,ll(root->val)-1);
             bool check_BSTR=isBST(root->right,ll(root->val)+1,(ll)max);

            return(check_BSTL && check_BSTR);

        }

        bool isValidBST(TreeNode* root) 
        {
            return isBST(root,-2200000000,2200000000);
        }
};