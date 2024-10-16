class Solution {
public:
    int count(vector<vector<int>>& matrix, int v){
        int c = 0, n = matrix.size();
        for(int i = 0; i < n; i++) c += upper_bound(matrix[i].begin(), matrix[i].end(), v) - matrix[i].begin();
        return c;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0], h = matrix[n-1][n-1], m;
        while(l < h){
            m = l + (h - l) / 2;
            int c = count(matrix, m);
            if(c < k) l = m + 1;
            else h = m;
        }
        return l;
    }
};