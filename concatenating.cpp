class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0;
        map<string, int> mp;
        int cnt = 0;
        
        for(auto &i: words) {
            if(i[0] == i[1]) {
                mp[i]++;
                if(mp[i] > 1) {
                    ans += 4;
                    mp[i] -= 2;
                }
                continue;
            }
            string x = "";
            x += i[1];
            x += i[0];
            if(mp[x] > 0) {
                mp[x]--;
                ans += 4;
            }
            else {
                mp[i]++;
            }
        }       
        for(auto &[x,y]: mp) {
            if(x[0] == x[1]) {
                if(mp[x] == 1)
                return ans+2;
            }
        }
        
        return ans+cnt;
    }
};
