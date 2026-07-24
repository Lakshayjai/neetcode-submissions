class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
    
        vector<int> st;
        
        for(auto it : asteroids){
            if(it > 0){
                st.push_back(it);
            }else{
                while(!st.empty() and st.back() > 0 and st.back() < abs(it)){
                    st.pop_back();
                }

                if(!st.empty() and st.back() == abs(it)){
                    st.pop_back();
                }
                else if(st.empty() ||
                        st.back() < 0){
                    
                    st.push_back(it);
                }
            }
        }

        return st;
    }
};