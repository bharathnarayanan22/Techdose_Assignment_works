class Solution { 
public:
    int xor1toN(int n) {  
    switch (n & 3) { 
    case 0: 
        return n; 
    case 1: 
        return 1; 
    case 2: 
        return n + 1; 
    case 3: 
        return 0; 
    }
    return 0;
    }
    
    vector<int> decode(vector<int>& encoded) {
        int enc = 0;
        int n = encoded.size()+1;
        vector<int> ans;
        for(int i=0;i<encoded.size();i+=2){
            enc ^= encoded[i];
        }
        int xorfull = xor1toN(n);
        int ele = xorfull ^ enc;
        ans.push_back(ele);
        for(int i=n-2;i>=0;--i){
            ele = ele^encoded[i];
            ans.push_back(ele);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};