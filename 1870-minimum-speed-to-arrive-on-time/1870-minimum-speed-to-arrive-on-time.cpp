class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
 int n = dist.size();
    int l = 1;
    int r = 10000000;
    int minspeed = -1;

    while(l <= r){
        int m = (l+r)/2;
        double t = 0;
        for(int i = 0; i<n; i++){
            if(i == n-1){
                t += dist[i]/(double)(m);
            }
            else if(dist[i] <= m){
                t += 1;
            }
            else{
                double x = dist[i]/double(m);
                int y = dist[i]/m;
                if(y < x){
                    t += y+1;
                }
                else{
                    t += y;
                }
            }
          }
          if(t <=  hour){
              minspeed = m;
              r = m-1;
          }
          else{
             l = m+1;
          }

    }

return minspeed;
    }
};