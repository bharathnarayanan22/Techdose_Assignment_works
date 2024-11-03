class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int h = nums.size()-1;
        while(l < h){
            int m = l + (h-l)/2;
            if(nums[m] > nums[m + 1]) h = m;
            else l = m + 1;
        }
        if(l == nums.size()-1) return nums[0];
        return nums[l+1];
    }
};