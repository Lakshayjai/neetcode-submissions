class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int cnt = 0;

        vector<vector<bool>> pal(n, vector<bool>(n, false));

        for(int i = n-1; i >= 0; i--){
            for(int j = i; j < n; j++){
                if(s[i] == s[j] and (j - i <= 2 or pal[i+1][j-1])){
                    
                    pal[i][j] = true;
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
