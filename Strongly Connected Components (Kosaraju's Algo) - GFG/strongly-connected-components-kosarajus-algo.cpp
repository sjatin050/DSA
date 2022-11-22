// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	vector<int> vis,vis1;
	stack<int> st;
	// dfs calls to fill the stack
	void dfs(int src,vector<int> adj[])
	{
	    vis[src]=1;
	    for(auto x:adj[src])
	    {
	        if(vis[x]==0)
	        {
	            dfs(x,adj);
	            
	        }
	    }
	    st.push(src);
	}
	// after stack calls (poping the elements)
	void dfs1(int src,vector<int> adj[])
	{
	    vis1[src]=1;
	    //cout<<src<<" ";
	    for(auto x:adj[src])
	    {
	        if(vis1[x]==0)
	        {
	            
	            dfs1(x,adj);
	        }
	    }
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        /// used to fill the stack
        vis.resize(V);
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
            {
                dfs(i,adj);
                // // push the values when the function calls the finished
                // st.push(i);
            }
        }
        vis1.resize(V,0);
        // used to transpose the adj list
        vector<int> adjTranspose[V];
        for(int i=0;i<V;i++)
        {
            for(auto x:adj[i])
            {
                adjTranspose[x].push_back(i);
            }
        }
        int cnt=0;
        // used to cnt the no connected components
        // single node itself is a connected component
        while(!st.empty())
        {
            
            int ele=st.top();
            st.pop();
            if(vis1[ele]==0)
            {
                //cout<<"scc--> ";
                //cout<<ele<<"\n";
                dfs1(ele,adjTranspose);
                cnt++;
            }
            //cout<<"\n";
        }
        return cnt;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends