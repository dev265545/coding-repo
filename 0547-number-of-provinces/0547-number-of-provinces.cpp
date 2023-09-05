class Solution {
public:
    void dfs(int i, vector<vector<int>> &v, vector<bool> &vis ){
        vis[i]= true;
        for(int j=0;j<v.size();j++){
              if(v[i][j]==1 && !vis[j]){
                dfs(j,v,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count=0;
        int row=isConnected.size();
        vector<bool> visited(row,false);
        for(int i=0;i<row;i++){
            if(!visited[i]){
                dfs(i,isConnected,visited);
                count++;
            }
        }
        return count;
    }
};