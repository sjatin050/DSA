class Solution {
public:
	vector<int> fac={9,81,648,4536,27216,136080,544320,1632960,3265920};     // all possible number with digits given as index
    vector<int> fact={1,1,2,6,24,120,720,5040,40320,362880,3628800};        // factorial array
    int countSpecialNumbers(int x) {
        vector<bool> vis(10,false);
        int ans=0;
        int y=x;
        int n=0;
        while(y){
            n++;
            y/=10;
        }
        int c=0;
        for(int i=0;i<n-1;i++){
					ans+=fac[i];                                                 // count number whose digits are less than that digit
        }
        bool flag=true;
        // if does not understand the process just debug with no 135 , 394 .. you will get the solution
        for(int i=n-1;i>=0;i--)
        {
             c++;
            int m=x/(pow(10,i));
            // we are not decreasing m by 1 beacause 
            // as we know 0 to m there are m+1 no's ... but we want all no's which are less than equal to (m-1)99999..
            int t=m;   
            m=m%10;
            int y=m;  
            if(i==n-1){ // beacuse at first place 0 should not come
                m--;
            }
           
            int u=m;  
            for(int j=0;j<u;j++)
            {
                if(vis[j])
                {
                    m--;
                }                   
            }   
            
            
            ans+=(m*(fact[10-c]/fact[10-i-c]));
            // see if the digit is visited again then break
            if(vis[y]) // suppose we are finding values for 4991 or 49191 .. so after 2nd 9 the loop should break
                        // because no num can after that can be included
            {
                flag=false;
                break;
            } 
            vis[y]=true; 
        }
        if(flag)
            ans++;
        return ans;
    }
};