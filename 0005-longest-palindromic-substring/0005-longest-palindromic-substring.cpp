class Solution {
public:
    string longestPalindrome(string s) 
    {
        int n=s.length();
        vector<char> newStr(2*n+1);
        int i=0;
        newStr[i++]='#';
        for(auto x:s)
        {
            newStr[i++]=x;
            newStr[i++]='#';
        }
        vector<int> p(2*n+1);
        int center=0,right=0;
        int longestLength=0,longestCenter=0;
        // hum p array me keval half length ki string store karenge kyu ki baki hum double kar ke nikal sakte hai
        for(i=0;i<newStr.size();i++)
        {
            // i th ele value phele bhi aaya hoga left me center ke , to fir se fill karne ki jagha hum wahi value rakh dete hai
            // 
            int mirror= 2*center-i;
            // taking the values from prefix
            // 
            if(right>i)
            {
                
                // p[mirrior] value could be large and could exceed the right point value
                // (right -i) is liye kiya  jis se vo initial max sustring ke right end se exceed naa ho
                p[i]=min(p[mirror],right-i);
            }
            // now calculating the length of the palindrome from center taken
            // p[i]+1 is liye kiya hai kyu ki p[i]tak to match ho gyaa naa hume use aage kaa dekna hai
            // aagr +1 nahi kiya to palindrome ki length inc ho jaega ..which will give wrong ans
            int a=i + (p[i]+1);
            int b=i - (p[i]+1);
            
            while(b>=0 && a<newStr.size() && newStr[a]==newStr[b]){
                b--;
                a++;
                p[i]++;
            }
            // if length of palindrome is so far is more than before then update it
// this can be done afterwards also only we need to take max value from the arr p[]
            if(p[i]>=longestLength){
                longestCenter=i;
                longestLength=p[i];
            }
            // updating the center and its right value (if right becomes less from before)
            if(i+p[i]>right){
                center=i;
                right=i+p[i];
            }
        }
        string st;
        for(int i=0;i<2*n+1;i++)
        {
            cout<<p[i]<<" ";
        }
        cout<<"\n";
        for(int i=longestCenter-longestLength;i<longestCenter+longestLength;i++)
        {
            if(newStr[i]!='#')
            {
                st+=newStr[i];
            }
        }
        return st;
    }
};
//https://www.youtube.com/watch?v=IvakBbsAhUU&t=9s   (code from this video)
//https://www.youtube.com/watch?v=V-sEwsca1ak&t=781s   (tushar roy to understand it)
