class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i = n-1; i >= 0; i--){
            if(st.empty()){
                ans[i] = 0;
                st.push(i);
            }
            else if(t[st.top()] > t[i]){
                ans[i] = st.top() - i;
                st.push(i);
            }else{
                while(!st.empty() and t[st.top()] <= t[i]){
                    st.pop();
                }
                if(st.empty()){
                    ans[i] = 0;
                    st.push(i);
                }else{
                    ans[i] = st.top() - i;
                    st.push(i);
                }
            }
        }

        return ans;
    }
};
