class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> f;
        vector<int> res;
        for(int i=0; i<n; i++) f[nums[i]]++;
        for(auto i : f){
            if(i.second > (n/3)) res.push_back(i.first); 
        }
        return res;
    }
};