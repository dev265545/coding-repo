class Solution {
public:
    vector<TreeNode*> solve(int n){
        //even case=> no possible FBT
        unordered_map<int , vector<TreeNode*>>mp;
        if(n%2 == 0){
            return {};
        }
        //base case
        if(n == 1){
            TreeNode* root = new TreeNode(0);
            return {root};
        }
        vector<TreeNode*>res;
        if(mp.find(n) != mp.end()){
            return mp[n];
        }
        //baaki cases ke liy
        for(int i=1; i<n; i+=2){
            vector<TreeNode*> leftAllFBT = solve(i);
            vector<TreeNode*> rightAllFBT = solve(n-i-1);
            //ab leftAllFBT and rightAllFBT me saare nodes aa gye.
            //traverse krke ek ek ko apna left aur right baccha bnaalo guys.

            for(auto &l : leftAllFBT){
                for(auto &r : rightAllFBT){
                    TreeNode* root = new TreeNode(0);
                    root -> left = l;
                    root -> right = r;
                    res.push_back(root);
                }
            }

        }
        return mp[n] = res;

    }
    vector<TreeNode*> allPossibleFBT(int n) {
        return solve(n);
    }
};
