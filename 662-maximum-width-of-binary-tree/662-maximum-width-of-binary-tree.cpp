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
int widthOfBinaryTree(TreeNode* root) 
{
    queue<pair<TreeNode *,long long>> q;
    q.push({root,0});
    long long maxw=0;
    
    while(!q.empty())
    {
       int n=q.size();
       long long minm=q.front().second;
        
       long long first,last;
        
       for(int i=0;i<n;i++)
       {
           TreeNode *rt=q.front().first;
           // by doing the below condition the val will start from 0
           // because of which the value will not go out of long long range
           long long val=q.front().second-minm; // if not done this the long long will overflow
           
           q.pop();
           if(i==0)
               first=val;
           if(i==n-1)
               last=val;
           
           if(rt->left)
               q.push({rt->left,val*2+1});
           if(rt->right)
               q.push({rt->right,val*2+2});
           
       }
      maxw=max(maxw,last-first+1);  
    }
    return maxw;
}
};