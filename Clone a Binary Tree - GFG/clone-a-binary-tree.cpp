// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	struct Node *random;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	    random = NULL;
	}
};
int checkcloned(Node* a, Node *b)
{
	if ((a == NULL and b == NULL))
		return 1;

	if (a != NULL && b != NULL)
	{
		int t = (a->data == b->data && checkcloned(a->left, b->left) && checkcloned(a->right, b->right));

		if (a->random != NULL && b->random != NULL)
			return (t && a->random->data == b->random->data);
		if (a->random == b->random)
			return t;

		return 0;
	}

	return 0;

}

void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

 // } Driver Code Ends
/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node *random;
};
*/

class Solution{
  public:
    Node* util(Node* tree, bool isRandom) 
    {
        if(tree == NULL)
        return NULL;
        
        Node *clonedNode = new Node(tree->data);
        
        if(!isRandom) 
        {
            clonedNode->left = util(tree->left, false);
            clonedNode->right = util(tree->right, false);
            clonedNode->random = util(tree->random, true);
        }
        return clonedNode;
    }
    
    /* The function should clone the passed tree and return
    root of the cloned tree */
    Node* cloneTree(Node* tree)
    {
        //Your code here
        if(tree == NULL)
        return NULL;
        
        return util(tree, false);
    
    }
        /* The function should clone the passed tree and return 
           root of the cloned tree */
    // Node* cloneTree(Node* tree)
    // {
    //   unordered_map<int,int> mp;
    //   unordered_map<int,Node*> mp1;
       
    //   queue<Node*> qori;
    //   queue<Node*> qclo;
       
    //   Node *clonehead=new Node(tree->data);
    //   mp1[tree->data]=clonehead;
    //   qori.push(tree);
    //   qclo.push(clonehead);
       
    //   while(qori.size())
    //   {
    //       int si=qori.size();
    //       for(int i=0;i<si;i++)
    //       {
    //           auto x1=qori.front();
    //           qori.pop();
    //           auto x2=qclo.front();
    //           qclo.pop();
    //           if(x1->left)
    //           {
    //               Node* le=new Node(x1->left->data);
    //               x2->left=le;
    //               mp1[x1->left->data]=le;
    //               qori.push(x1->left);
    //               qclo.push(le);
    //           }
               
    //           if(x1->right)
    //           {
    //               Node* ri=new Node(x1->right->data);
    //               x2->right=ri;
    //               mp1[x1->right->data]=ri;
    //               qori.push(x1->right);
    //               qclo.push(ri);
    //           }
    //           if(x1->random)
    //           {
    //               mp[x1->data]=x1->random->data;
    //           }
               
               
    //       }
    //   }
    // //   cout<<mp.size()<<"\n";
    // //   cout<<mp1.size()<<"\n";
    // // now filling all the random pointers
    //   for(auto x:mp)
    //   {
    //       mp1[x.first]->random=mp1[x.second];
    //   }
       
    // //   queue<Node*> q;
    // //   q.push(clonehead);
    // //   while(q.size())
    // //   {
    // //       auto x=q.front();
    // //       q.pop();
    // //     //   cout<<x->data<<"-->";
    // //     //   if(x->random)
    // //     //   cout<<x->random->data;
    // //     //   cout<<"\n";
    // //       if(x->left)
    // //       {
    // //           q.push(x->left);
    // //       }
    // //       if(x->right)
    // //       {
    // //           q.push(x->right);
    // //       }
    // //   }
    //   //cout<<"\n";
    //   return clonehead;
       
       
    // }
};


// { Driver Code Starts.
/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d\n", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);

        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];

        child = new Node(n2);
        if (lr == 'L'){
          parent->left = child;
           m[n2]  = child;
        }
        else if(lr=='R'){
          parent->right = child;
           m[n2]  = child;
        }
        else{
          parent->random = m[n2];
        }


     }
     Solution obj;
     Node *t = obj.cloneTree(root);
     if(t==root)
        cout<<0<<endl;
     else
     cout<<checkcloned(root,t);
     cout<<"\n";
  }
  return 0;
}

  // } Driver Code Ends