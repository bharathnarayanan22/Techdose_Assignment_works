// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long int l = 1;
        long int h = n;
        long int mid;
        long int res = n;
        while(l <= h){
            mid = (l + h) / 2;
            if(isBadVersion(mid)){
                res = mid;
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        return res;

    }
};