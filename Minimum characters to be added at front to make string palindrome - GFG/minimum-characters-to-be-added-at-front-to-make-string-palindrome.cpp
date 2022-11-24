// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
// See leetcode submission for more clearence

// the algo followed is below
// let string A= aacecaaaa  and string of length be n
// then B=rev(A)=aaaacecaa
//now  A+B = aacecaaaaaaaacecaa
// the the longest string which is prefix and suffix also --> aacecaa  { from A+B }
// this means the prefix we get is the longest palindrome the original string has
// so now we will add elements from string B -->  i.e. B.substr(0,(n-len(prefix))) in front
    vector<int> calculate_lps(string s)
    { 
            int i=0,j=1;
    	    int n=s.size();
    	    vector<int> pre(n);
    	    while(i<n && j<n)
    	    {
    	        // the second condtion is applied after end so that suffix do not overlap prefix.. like in this case aabbaabba it gives aabba which is more than n/2 (len of string ).
               // if both are eaual then just update the pre[j] with the i+1
    	        if(s[i]==s[j] && i+1<=(n+1)/2)
    	        {
    	            pre[j]=i+1;
    	            i++;
    	            j++;
    	        }
    	        else
    	        {
    	            if(i!=0)
    	            i=pre[i-1];
    	            else
    	            {
    	                j++;
    	            }
    	        }
    	    }
    	    return pre;
    }

    int minChar(string A)
    {
        int n = A.length();
        string B = A;
        reverse(B.begin(),B.end());
        A = A + B;
        vector<int>lps = calculate_lps(A);
        lps[2*n-1] = min(n, lps[2*n-1]);
        // the string which will come in front will be B.substr(0,n-lps[2*n-1])
        return n-lps[2*n-1];
        
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.minChar(str);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends