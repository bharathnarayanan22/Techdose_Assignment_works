class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int> st;
        for(auto i : nums){
            st.insert(i);
            if (st.size() > k) {
                st.erase(st.begin());
            }
        }
        return *st.begin();
        
    }
};