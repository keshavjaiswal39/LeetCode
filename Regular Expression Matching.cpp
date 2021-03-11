class Solution 
{
public:
    bool isMatch(string s, string p) 
	{
		bool dp[p.size()+1][s.size()+1];
		
		for(int i=0;i<=p.size();i++)
		{
			for(int j=0;j<=s.size();j++)
			{
				if(i==0 and j==0)
				{
					// mtlb dp[0][0]
					dp[i][j]=true;
				}
				
				else if(i==0)
				{
					// pehle row mein sab false hojayega
					dp[i][j]=false;
				}
				
				else if(j==0)
				{
					char pc=p[i-1];
					
					if(pc=='*')
					{
						// do row upar dekhna hai
					    dp[i][j]=dp[i-2][j];
                    }
                    
                    else
                    {
                        dp[i][j]=false;
                    }
				}
				
				else
				{
					char pc=p[i-1];
					char sc=s[j-1];
					
					if(pc=='*')
					{
						dp[i][j]=dp[i-2][j];
						
						char pslc=p[i-2];
						
						if(pslc==sc or pslc=='.')
						{
							dp[i][j]=dp[i][j] or dp[i][j-1];
						}
					}
					
					else if(pc=='.')
					{
						dp[i][j]=dp[i-1][j-1];
					}
					
					else if(pc==sc)
					{
						dp[i][j]=dp[i-1][j-1];
					}
					
					else
					{
						dp[i][j]=false;
					}
				}
			}
		}
        return dp[p.size()][s.size()];
    }
};
