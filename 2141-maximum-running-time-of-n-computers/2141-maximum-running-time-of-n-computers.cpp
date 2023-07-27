class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        sort(batteries.begin(), batteries.end());
        long long s = 1, e=LLONG_MAX, ans=0;
        while(s<=e){
            long long sum=0, mid = s + (e-s)/2;
            int x=n;
            for(int it:batteries){
                sum += it;
                if(sum >= mid){
                    x--; 
                    sum -= mid; 
                }
            }
            if(x<=0){ 
                ans = max(ans, mid);
                s = mid+1;
            }else e = mid-1;
        }
        return ans;
    }
};