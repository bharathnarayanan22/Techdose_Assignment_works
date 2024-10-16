class Solution {
public:
    void sol(int p,vector<int> &v)
    {
        while(p%2==0)
        {
            v.push_back(2);
            p=p/2;
        }
        for(int i=3;i<=sqrt(p);i=i+2)
        {
            while(p%i==0)
            {
                v.push_back(i);
                p=p/i;
            }
        }
        if(p>2)
        {
            v.push_back(p);
        }
        
    }
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int> st;
        vector<int> v;
        for(int i=0;i<nums.size();i++)
        {
            sol(nums[i],v);
        }
        for(int i:v) st.insert(i);
        return st.size();
    }
};