class Solution {
public:
    int hammingDistance(int x, int y) {
        int xorval = x^y;
        int c = 0;
        while(xorval){
            if(xorval & 1)
                c++;
            xorval>>=1;
        }
        return c;
    }
};