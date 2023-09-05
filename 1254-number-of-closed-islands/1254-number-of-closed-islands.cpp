class Solution {
public:
    void solve(int i, int j,int n, int m, vector<vector<int>>&grid, vector<vector<bool>>&vis, int &count)
    {
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==1 || vis[i][j]==true) return;
        vis[i][j]=true;

        if(i==0 || j==0 || i==n-1 || j==m-1) count++;

        solve(i+1,j,n,m,grid,vis,count);
        solve(i,j+1,n,m,grid,vis,count);
        solve(i-1,j,n,m,grid,vis,count);
        solve(i,j-1,n,m,grid,vis,count);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        int ans=0;
        vector<vector<bool>>vis(n, vector<bool>(m));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 || vis[i][j]==true) continue;
                int count=0;
                solve(i,j,n,m,grid,vis,count);

                if(count==0) ans++; 
            }
        }
        return ans;
    }
};