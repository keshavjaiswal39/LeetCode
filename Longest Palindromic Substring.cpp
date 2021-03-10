class Solution {
public:
    string longestPalindrome(string s) 
    {
        int maxLength=1;
        int start=0;
        int len=s.size();
        
        if(len==1)
        {
            return s;
        }
        
        int low,high;
        
        for(int i=0;i<len;i++)
        {
            low=i-1;
            high=i;
            
            while(low>=0 and high<len and s[low]==s[high])
            {
                if(high-low+1>maxLength)
                {
                    start=low;
                    maxLength=high-low+1;
                }
                low--;
                high++;
            }
            
            low=i-1;
            high=i+1;
            while(low>=0 and high<len and s[low]==s[high])
            {
                if(high-low+1>maxLength)
                {
                    start=low;
                    maxLength=high-low+1;
                }
                low--;
                high++;
            }
        }
                    
        return s.substr(start,maxLength);
               
    }
};
