class Solution {
public:
    int count=0;
    void helper(int i , vector<int>&dp , vector<vector<int>>&C){
        int m = C[i].size();
        for(int j = 0; j< m ;j++){
            if(dp[C[i][j]]==0)
                return;
        }
        dp[i]=1;
        count++;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>>C(n);
        int m = pre.size();
        vector<int>dp(n);
        for(int i =0 ; i< m ;i++){
            C[pre[i][0]].push_back(pre[i][1]);
        }
        for(int i = 0 ; i < n ; i++){
            if(C[i].size()==0){
                count++;
                dp[i]=1;
            }
        }
        while(count!=n){
            int cur = count;
            for(int i =0 ; i< n ;i++){
                if(dp[i]==0){
                    helper(i,dp,C);
                }
            }
            if(cur==count)
                return false;
        }
        return true;
    }
};