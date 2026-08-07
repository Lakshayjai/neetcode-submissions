class Solution {
public:
    void helper(queue<string>& que, string curr, unordered_set<string>& st){

        for(int i = 0; i < 4; i++){
            char ch = curr[i];

            char dec = ch == '0' ? '9' : ch-1;
            char inc = ch == '9' ? '0' : ch+1;

            curr[i] = dec;
            if(st.find(curr) == st.end()){
                st.insert(curr);
                que.push(curr);
            }

            curr[i] = inc;
            if(st.find(curr) == st.end()){
                st.insert(curr);
                que.push(curr);
            }

            curr[i] = ch;
        }

    }

    int openLock(vector<string>& deadends, string target) {

        unordered_set<string> st(deadends.begin(), deadends.end());

        if(st.find("0000") != st.end()){
            return -1;
        }

        string start = "0000";

        queue<string> que;
        que.push(start);

        int level = 0;
        while(!que.empty()){

            int n = que.size();

            while(n--){
                string curr = que.front();
                que.pop();

                if(curr == target) return level;

                helper(que, curr, st);
            }
            level++;
        }

        return -1;
    }
};