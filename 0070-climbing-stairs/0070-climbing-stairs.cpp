class Solution {
public:
    int climbStairs(int n) {
        int one =1 ;
        int two = 2;
        if(n==1){
            return 1;
        }
        else if(n==2){
            return 2;
        }
        else {
         for(int i =3;i<=n;i++){
             int t = one + two;
             one = two;
             two = t;
         }   
        }
        return two;
    }
};