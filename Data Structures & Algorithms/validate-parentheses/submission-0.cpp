class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto it : s){
            if(it == '[' or it == '(' or it == '{'){
                st.push(it);
            }else{
                if(st.size() == 0) return false;

                if(it == ']'){
                    if(st.top() == '[') st.pop();
                    else return false;
                }

                if(it == ')'){
                    if(st.top() == '(') st.pop();
                    else return false;
                }
                
                if(it == '}'){
                    if(st.top() == '{') st.pop();
                    else return false;
                }
            }
        }

        if(st.size() != 0) return false;
        return true;
    }
};
