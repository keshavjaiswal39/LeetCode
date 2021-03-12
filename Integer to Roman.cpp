class Solution {
public:
    int roman(int n,int k,string c,string &s)
    {
        if(n==9)
        {
            s += "IX";
            return 0;
        }
        if(n==4)
        {
            s += "IV";
            return 0;
        }
        
        while(n>=k)
        {
            s += c;
            n=n-k;
        }
        return n;
    }
    
    string intToRoman(int num) 
    {
        string s;
        
        while(num>0)
        {
            if(num>=1000)
            {
                num=roman(num,1000,"M",s);
            }
            
            if(num>=900)
            {
                num=roman(num,900,"CM",s);
            }

            if(num>=500)
            {
                num=roman(num,500,"D",s);
            }
            
            if(num>=400)
            {
                num=roman(num,400,"CD",s);
            }

            if(num>=100)
            {
                num=roman(num,100,"C",s);
            }
            
            if(num>=90)
            {
                num=roman(num,90,"XC",s);
            }

            if(num>=50)
            {
                num=roman(num,50,"L",s);
            }
            
            if(num>=40)
            {
                num=roman(num,40,"XL",s);
            }

            if(num>=10)
            {
                num=roman(num,10,"X",s);
            }

            if(num>=5)
            {
                num=roman(num,5,"V",s);
            }

            if(num>=1)
            {
                num=roman(num,1,"I",s);
            }
        }
        
        return s;
    }
    
    
};
