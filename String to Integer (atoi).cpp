class Solution 
{
	public:
    	int myAtoi(string s) 
    	{
        	int i=0;
        	int sign=1;
        	int result=0;
        	
        	if(s.size()==0)
        	{
        		return 0;
			}
			
			// Discard the white spaces
			while(i<s.size() and s[i]==' ')
			{
				i++;
			}
			
			// Check if the optional sign if it exists
			if(i<s.size() and (s[i]=='+' or s[i]=='-'))
			{
				sign=(s[i++]=='-')?-1:1;
			}
			
			// Lets build the result and at the same time we will also check for the overflow/underflow condition
			while(i<s.size() and s[i]>='0' and s[i]<='9')
			{
				if(result>INT_MAX/10 or (result==INT_MAX/10 and s[i]-'0'>INT_MAX%10))
				{
					return (sign==1)?INT_MAX:INT_MIN;
				}
				
				result=result*10+(s[i++]-'0');
			}
			
			return result*sign;
    	}
};
