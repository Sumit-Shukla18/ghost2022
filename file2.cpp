class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> v(52);
        for(int i = 0; i<s.size(); i++) {
            if(s[i] >= 'a') {
                v[s[i] - 'a']++;
            }
            else {
                v[25 + (s[i] - 'A')]++;
            }
        }
        int ans = 0;
        bool flag = true;
        for(auto &i: v) {
            ans += (i/2*2);
            if(i%2 == 1) flag = false;
        }
        if(ans%2 == 0 and !flag) ans++; 
        return ans;
    }
};
