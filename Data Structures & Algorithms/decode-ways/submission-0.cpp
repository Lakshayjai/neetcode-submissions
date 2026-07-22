class Solution {
public:
    
    int f(int i, string& s, int n, vector<int>& t){

        if(t[i] != -1) return t[i];
        if(i == n) return 1;  // one valid split done

        if(s[i] == '0') return 0; // not possible to split

        int result = f(i+1, s, n, t);
        
        if(i + 1 < n and (s[i] == '1' or (s[i] == '2' and s[i+1] <= '6')))
            result += f(i+2, s, n, t);

        return t[i] = result;
    }

    int numDecodings(string s) {
        int n = s.length();
        vector<int> t(101, -1);

        // memset(t, -1, sizeof(t));
        return f(0, s, n, t);
    }
};
