class Solution {
public:
    vector<int> sum(vector<int>& nums,int st,int end,int offset){        
        vector<int> res;
        int n=end-st+1;
        for(int i=0;i<(1<<n);++i){
            int sum=0;
            for(int j=0;j<n;++j){
                if(i&(1<<j))
                    sum+=nums[j+offset];
            }
            res.push_back(sum);
        }
        return res;
    }
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        if(n == 1) return min(abs(goal), abs(nums[0] - goal));
        vector<int> fh = sum(nums, 0, n/2-1, 0);
        vector<int> sh = sum(nums, n/2, n-1, n/2);
        sort(sh.begin(), sh.end());
        int res = INT_MAX;
        for(int i = 0; i < fh.size(); i++) {
            int lb = lower_bound(sh.begin(), sh.end(), goal - fh[i]) - sh.begin();
            if(lb > 0) res = min(res, abs(goal - sh[lb-1] - fh[i]));
            if(lb < sh.size()) res = min(res, abs(goal - sh[lb] - fh[i]));
        }
        return res;
    }
};