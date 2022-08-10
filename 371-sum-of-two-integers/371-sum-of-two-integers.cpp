class Solution {
public:
    int getSum(int a, int b) {
        if(a==0)
            return b;
        if(b==0)
            return a;
        
        int sum = 0;
        int mask = 1;
        int c=0;
        
        while(mask!=0)
        {
            int m1 = (a &mask)!=0?1:0;
            int m2 = (b &mask)!=0?1:0;
            
            if(m1==1 && m2==1)
            {
                if(c==1)
                    sum|=mask;
                
                c=1;
            }
            
            else if((m1^m2)==1)
            {
                if(c==1)
                    c=1;
                else
                    sum |=mask;
            }
            else 
            {
                if(c==1)
                {
                    sum|=mask;
                }
                c=0;
            }
          
            mask= (0xffffffff &mask)<<1;
            
            if(mask>2*max((a&0xffffffff)<<1,(b&0xffffffff)<<1))
                break;
        }
    
        return sum;  
    }
};