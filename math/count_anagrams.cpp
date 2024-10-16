class Solution {
public:
    long long mod = 1000000007;
    long long binpow(long long a, long long b){
        long long ans = 1;
        while(b > 0){
            if(b % 2 == 1){
                ans = (ans * a) % mod;
            }
            b >>= 1;
            a = (a * a) % mod;
        }
        return ans;
    }
    long long inv(long long n){
        return binpow(n, mod - 2);
    }
    long long getDistinctWays(string word, vector<long long>& fact){
        vector <long long> f(26);
        for(auto& c : word){
            f[c - 'a']++;
        }

        long long n = word.length();

        long long ans = fact[n];
        for(auto& cnt : f){
            if(cnt > 0){
                ans = (ans * inv(fact[cnt])) % mod;
            }
        }

        return ans;
    }
    int countAnagrams(string s) {
        int n = s.length();
        string word = s.substr(0,1);
        vector<long long> fact(n+1, 1);

        for(long long i = 1; i <= n; i++){
            fact[i] = (i * fact[i-1]) % mod;
        }

        long long ans = 1;
        for(int i = 1; i < n; i++){
            if(s[i] == ' '){
                ans = (ans * getDistinctWays(word, fact)) % mod;
                word.clear();
            }
            else{
                word.push_back(s[i]);
            }
        }

        ans = (ans * getDistinctWays(word, fact)) % mod;

        return (int)ans;
    }
};