class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        int m = haystack.size(), n = needle.size();
        if (n==0) 
        {
            return 0;
        }
        vector<int> lps = kmpProcess(needle);
        // i--> haystack
        // j--> needle
        for (int i = 0, j = 0; i < m;) 
        {
            if (haystack[i] == needle[j]) { 
                i++, j++;
            }
            // if neeedle last char match then return index 
            if (j == n) 
            {
                return i - j;
            }
            // same process done as we do while making lps of needle
            // use the kmpp table of needle to find the other occurence of element set in haystack by going back using kmp table
            if (i < m && haystack[i] != needle[j]) 
            {
                if(j!=0)
                {
                    j=lps[j-1];
                }
                else
                    i++;
            }
        }
        return -1;
    }
private:
    // make the kmp table of string to be searched
    vector<int> kmpProcess(string needle) 
    {
        int n = needle.size();
        vector<int> lps(n, 0);
        for (int j = 1, i = 0; j < n;) 
        {
            if (needle[i] == needle[j]) 
            {
                lps[j] = i+1;
                j++;
                i++;
            } 
            else 
            {
                if (i!=0) 
                i = lps[i - 1];
                else
                    j++;
            } 
            
        }
        return lps;
    }
};