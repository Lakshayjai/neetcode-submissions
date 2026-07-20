class Solution {
public:
    int maxArea(vector<int>& h) {
        int n = h.size();

        int i = 0;
        int j = n-1;

        int ans = 0;

        while(i < j){
            if(h[i] < h[j]){
                int area = h[i] * (j-i);
                ans = max(ans, area);
                i++;
            }else if(h[i] > h[j]){
                int area = h[j] * (j-i);
                ans = max(ans, area);
                j--;
            }else{
                int area = h[j] * (j-i);
                ans = max(ans, area);
                i++;
                j--;
            }
        }
        return ans;
    }
};
