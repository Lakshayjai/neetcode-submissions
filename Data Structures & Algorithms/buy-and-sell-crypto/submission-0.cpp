class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;
        int bp = prices[0];
        for(int i = 1; i < n; i++){
            int sp = prices[i];
            if(sp > bp){
                int profit = sp - bp;
                maxProfit = max(maxProfit, profit);
            }else{
                bp = min(bp, sp);
            }
        }
        return maxProfit;
    }
};
