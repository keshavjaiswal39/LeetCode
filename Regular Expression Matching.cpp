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
					// pehle column mein check karlenge ki character * toh nai hai na
					char pc=p[i-1];
					
					// agar asterisk hua toh two tows upar dekhenge
					if(pc=='*')
					{
						// do row upar dekhna hai
					    dp[i][j]=dp[i-2][j];
                    }
                    
                    // warna false hojayega if pc == 'a to z' ya '.'
                    else
                    {
                        dp[i][j]=false;
                    }
				}
				
				else
				{
					// yeh hum abb 1st row and 1st col ke alawa jitna bhi grid hai uske liye check karenge
					char pc=p[i-1];
					char sc=s[j-1];
					
					// agar pattern ka character '*' hai
					if(pc=='*')
					{
						// toh pehle uce row mein two steps upar dekhenge
						dp[i][j]=dp[i-2][j];
						
						// fir ek variable mein pattern ki i-2th character ko store karenge
						char pslc=p[i-2];
						
						// agar pslc == string ki last character hai aur pslc=='.' hai toh fir hum
						if(pslc==sc or pslc=='.')
						{
							// then pehle jo is index pe dp ki value thi aur ek row pehle dp ki jo value hai
							// un dono ke bich ka or lenge
							dp[i][j]=dp[i][j] or dp[i][j-1];
						}
					}
					
					// agar pattern ki character '.' hai toh ucse upar ka diagonal dekhenge
					else if(pc=='.')
					{
						dp[i][j]=dp[i-1][j-1];
					}
					
					// agar pattern ki character aur string ki character same hai toh ucse upar ka diagonal dekhenge
					else if(pc==sc)
					{
						dp[i][j]=dp[i-1][j-1];
					}
					
					// warna false return hojayega dp mein
					else
					{
						dp[i][j]=false;
					}
				}
			}
		}
		
		// dp ki last row aur col mein jo bhi value hgi woh humara answert hoga 
        return dp[p.size()][s.size()];
    }
};
