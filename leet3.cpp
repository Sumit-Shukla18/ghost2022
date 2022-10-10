class Solution {
public:
    int minimumLines(vector<vector<int>>& vv) {
        if(vv.size() == 1) return 0;
    
        sort(vv.begin(), vv.end());
                
        int x = vv[1][0] - vv[0][0], y = vv[1][1] - vv[0][1];
        int cnt = 1;
        
        for(int i = 2; i<vv.size(); i++) {
            int x1 = vv[i][0] - vv[i-1][0];
            int y1 = vv[i][1] - vv[i-1][1];
            
            long double d1 = (long double)y1/x1;
            long double d2 = (long double)y/x;
            
            if(d1 != d2) {
                cnt++;
            }
            x = x1;
            y = y1;
        }
        
        return cnt;
    }
};
