class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size() ;
        int c = matrix[0].size() ;
        int l = 0 ;
        int r = row*c - 1 ;
        int m = (l+r)/2;
        while(l<=r){
            int element = matrix[m/c][m%c];
            if(target == element){
                return 1;
            }
            else if(target <= element){
                r=m-1;
            }
            else {
                l=m+1;
            }
            m = (l+r)/2;
        }
        return 0;
        
    }
};