class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pt(numRows);
        for(int row = 0; row <numRows; row++){
            pt[row].resize(row+1);
            pt[row][0] = pt[row][row] = 1;
            for(int pos = 1; pos<row; pos++){
                pt[row][pos] = pt[row-1][pos-1] + pt[row-1][pos];
            }
        }
        return pt;
    }
};