class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int ind = 0;
        while(arr[ind]<arr[ind+1]){
            ind++;
        }
        return ind;

    }
};