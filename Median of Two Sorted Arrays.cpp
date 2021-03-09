class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int n1=nums1.size();
        int n2=nums2.size();
        
        // if size of array 1 is greater than array 2 then we interchange the vector and the size value in n1 and n2
        if(n1>n2)
        {
            vector<int> temp=nums1;
            nums1=nums2;
            nums2=temp;
            
            int num=n1;
            n1=n2;
            n2=num;
        }
        
        double ans=0.0;

        if(n1==0)
        {
            return n2%2==0?(((double)nums2[n2/2-1]+(double)nums2[n2/2])/2):(double)nums2[n2/2];
        }
        
        if(n2==0)
        {
            return n1%2==0?(((double)nums1[n1/2-1]+(double)nums1[n1/2])/2):(double)nums1[n1/2];
        }
        
        int l=0;
        int h=n1;
        
        while(l<=h)
        {
            int cut1=(l+h)/2;
            int cut2=(n1+n2)/2-cut1;
            
            int l1 = cut1==0?INT_MIN:nums1[cut1-1];
            int l2 = cut2==0?INT_MIN:nums2[cut2-1];
            
            int r1 = cut1==n1?INT_MAX:nums1[cut1];
            int r2 = cut2==n2?INT_MAX:nums2[cut2];
            
            if(l1>r2)
            {
                h=cut1-1;
            }
            else if(l2>r1)
            {
                l=cut1+1;
            }
            else
            {
                ans=(n1+n2)%2==0?((double)max(l1,l2)+(double)min(r1,r2))/2:(double)min(r1,r2);
                break;
            }      
        }
        
        return ans;
    }
};
