class Solution {
public:
    
    // int value(char r) 
    // {
    //     if (r == 'I') return 1;
    //     else if (r == 'V') return 5;
    //     else if (r == 'X') return 10;
    //     else if (r == 'L') return 50;
    //     else if (r == 'C') return 100;
    //     else if (r == 'D') return 500;
    //     else if (r == 'M') return 1000;
    // }
    
    int romanToInt(string str) 
    {
        unordered_map<char,int> mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
         int res = 0;
    
        // Traverse given input
        for (int i = 0; i < str.length(); i++) 
        {
            // Getting value of symbol s[i]
            int s1 =mp[str[i]];
    
            if (i + 1 < str.length()) 
            {
                // Getting value of symbol s[i+1]
                int s2 = mp[str[i + 1]];
    
                // Comparing both values
                if (s1 >= s2) {
                    // Value of current symbol is greater
                    // or equal to the next symbol
                    res = res + s1;
                } else {
                    res = res + s2 - s1;
                    i++; // Value of current symbol is
                         // less than the next symbol
                }
            } else {
                res = res + s1;
                
            }
        }
        return res;
    }
};