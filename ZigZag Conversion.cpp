class Solution {
public:
    string convert(string s, int numRows) 
    {
    	int len=s.size();
		
		if(numRows>len or numRows<=1)
		{
			return s;
		}
		
		string res;
		int count=0;
		
		int interval=2*numRows-2;
		
		for(int i=0;i<numRows;i++)
		{
			int step=interval-2*i;
			
			for(int j=i;j<len;j+=interval)
			{
				res+=s[j];
				count++;
				
				if(step>0 and step<interval and j+step<len)
				{
					res+=s[j+step];
					count++;
				}
			}
		}
		return res;  
    }
};
