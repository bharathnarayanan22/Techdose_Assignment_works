class Solution {
public:
    int binarySearch(vector<int>& nums, int target, bool isSearchingLeft) {
        int l = 0;
        int r = nums.size() - 1;
        int idx = -1;
        
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] > target) {
                r = mid - 1;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                idx = mid;
                if (isSearchingLeft) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }    
        return idx;
    }    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {-1, -1};
        int left = binarySearch(nums, target, true);
        int right = binarySearch(nums, target, false);
        result[0] = left;
        result[1] = right;
        return result;        
    }
};