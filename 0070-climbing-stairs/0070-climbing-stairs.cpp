class Solution {
public:
    int climbStairs(int n) {
        int one = 1;
        int two = 2;
        int t;
         if(n==1) return 1;
        if(n==2)return 2;
        for(int i=3;i<=n;i++){
             t = one + two;
            one = two;
            two =t;
        }
        
    return t;
    }
};