//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}



// } Driver Code Ends
//User function Template for C++

/*
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
*/


class Solution{
public:
     unordered_map<Node*,Node*> mp;
    void fun(Node** root,string &s,int &i)
    {
        if(i==s.size())
        return;
        
        Node* curr=*root;
        if(s[i]=='(')
        {
            if(curr->left==NULL)
            {
                curr->left=new Node(-1);
                curr=curr->left;
            }
            else
            {
                curr->right=new Node(-1);
                curr=curr->right;
            }
            mp[curr]=*root;
          
            i++;
        }
        else if(s[i]==')')  // if finished,  go to its parent
        {
            curr=mp[curr];
            i++;
        }
        else
        {
            string temp="";
            while(i<s.size() && s[i]!='(' && s[i]!=')')
            {
               
                temp+=s[i];
                i++;
            }
            curr->data=stoi(temp);
        }
        fun(&curr,s,i);
    }
    
   

    // function to construct tree from string
    Node *treeFromString(string str)
    {
        int i=0;
        string temp;
        while(str[i] && str[i]!='(')
        {
            temp+=str[i];
            i++;
        }
        Node* root=new Node(stoi(temp));
        fun(&root,str,i);
        return root;
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends