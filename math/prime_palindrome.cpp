class Solution {
public:
    bool isprime(int n){
        for(int i = 2; i*i<=n; ++i){
            if((n % i) == 0){
                return false;
            }
        }
        return true;
    }
    bool isPalindrome(string s){
        int l = 0;
        int r = s.size()-1;
        while(l<=r){
        if(s[l] != s[r])
        return false;
        l++;
        r--;
        }
        return true;
    }
    int primePalindrome(int n) {
        if(n <= 2) return 2;
        if(n >= 9989900) return 100030001;
        if(n <= 11 and isprime(n)) return n;
        while(n!=0){
        if(isprime(n) && isPalindrome(to_string(n))){
            return n;
        }
        n++;
        }
        return -1;
    }
};