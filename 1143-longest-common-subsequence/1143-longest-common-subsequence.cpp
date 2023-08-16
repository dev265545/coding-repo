class Solution {
public:
    int getresult(string &text1,string &text2,vector<vector<int>>&dp,int indtext1,int indtext2)
    {
        
        if(indtext1==text1.length() && indtext2==text2.length())
        {
            return 0;
        }
        if(indtext1==text1.length() || indtext2==text2.length())
        {
            return 0;
        }
        
        if(dp[indtext1][indtext2]!=-1)
        {
            return dp[indtext1][indtext2];
        }
        
        if(text1[indtext1]==text2[indtext2])
        {
            return dp[indtext1][indtext2]=1+getresult(text1,text2,dp,indtext1+1,indtext2+1);
        }

        return dp[indtext1][indtext2]=max(getresult(text1,text2,dp,indtext1+1,indtext2),getresult(text1,text2,dp,indtext1,indtext2+1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int size1=text1.length(),size2=text2.length();
        vector<vector<int>>dp(size1,vector<int>(size2,-1));

        int data1=getresult(text1,text2,dp,0,0);
        if(data1<=0)
        {
            return 0;
        }
        return data1;
    }
};