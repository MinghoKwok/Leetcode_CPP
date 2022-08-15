class Solution {
public:
    string res="987654321";
    string smallestNumber(string pattern) {
        string s="";
        vector<int> vis(10,0);
        fun(vis,pattern,-1,s);
        return res;
    }
    void fun(vector<int>& vis,string& p,int i,string& s)
    {
        if(i==p.length())
        {
            if(res>s)
                res=s;
            return;
        }
        
        if(i==-1)
        {
            for(int j=1;j<=9;j++)
            {
                if(vis[j]==0)
                {
                    vis[j]=1;
                    s+=j+'0';
                    fun(vis,p,i+1,s);
                    s.pop_back();
                    vis[j]=0;
                }
            }
        }
        else
        {
            if(p[i]=='D')
            {
                int t=s[s.length()-1]-'0';
                for(int j=t-1;j>=1;j--)
                {
                    if(vis[j]==0)
                    {
                        vis[j]=1;
                        s+=j+'0';
                        fun(vis,p,i+1,s);
                        s.pop_back();
                        vis[j]=0;
                    }
                }
            }
            else
            {
                int t=s[s.length()-1]-'0';
                for(int j=t+1;j<=9;j++)
                {
                    if(vis[j]==0)
                    {
                        vis[j]=1;
                        s+=j+'0';
                        fun(vis,p,i+1,s);
                        s.pop_back();
                        vis[j]=0;
                    }
                }
            }
        }
    }
};