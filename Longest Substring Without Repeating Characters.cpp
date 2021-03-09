#include<bits/stdc++.h>
#include<string>
using namespace std;

int lengthOfLongestSubstring(string s)
{
	int n=s.size();
	
	vector<int> mapp(256,-1);
	
	int left=0;
	int right=0;
	
	int len=0;
	
	while(right<n)
	{
		if(mapp[s[right]]!=-1)
		{
			left=max(mapp[s[right]]+1,left);
		}
		
		mapp[s[right]]=right;
		
		len=max(len,right-left+1);
		right++;
	}
	return len;	
}

int main()
{
	string s;
	cin>>s;
	
	cout<<lengthOfLongestSubstring(s);
}







