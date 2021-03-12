class Solution {
public:
    int maxArea(vector<int>& v) 
    {
        int l=0;
        int h=v.size()-1;
        
        int res=0;
        
        while(l<h)
        {
            res=max(res,min(v[l],v[h])*(h-l));
            
            if(v[l]<v[h])
            {
                l++;
            }
            else
            {
                h--;
            }
        }
        
        return res;
    }
};
