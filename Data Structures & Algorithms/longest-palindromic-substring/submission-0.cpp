class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        string res = "";
        int resLen = 0;

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                int l = i;
                int r = j;

                while(l < r and s[l] == s[r]){
                    l++;
                    r--;
                }

                if(l >= r and resLen < (j - i + 1)){
                    res = s.substr(i, j - i + 1);
                    resLen = j - i + 1;
                }
            }
        }

        return res;
    }
};
