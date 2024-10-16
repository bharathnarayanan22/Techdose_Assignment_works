class Solution {
public:
    double myPow(double x, int y) {
        int n = abs(y);
        double res = 1.0;
        while(n >= 1){
            if(n%2 == 1){
                res *= x;
            }
            x = x*x;
            n = n/2;
        }
        return y<0 ? 1/res : res;
    }
};