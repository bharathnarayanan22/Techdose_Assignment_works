class Solution {
public:
    bool kSmaller(int n, int m, int x, int k) {
        int c = 0;
        int num = x/m;
        c+=m*num;
        for(int i=num;i<n;i++){
            c+=x/(i+1);
        }
        return c >= k;
    }
    
    int findKthNumber(int m, int n, int k) {
        int l = 0, h = m*n, mid, res;
        
        while (l < h) {
            mid = (l + h) / 2;
            
            if (kSmaller(n, m, mid, k)) h = mid;
            else l = mid + 1;
        }
        
        return l;
    }
};