class Solution {
public:
    int calPoints(vector<string>& operations) {
        int sum = 0;

        stack<int> st;
        for(auto it : operations){
            
            if(it == "C"){
                int first = st.top();
                st.pop();
                sum -= first;
            }
            else if(it == "+"){
                int first = st.top();
                st.pop(); 
                int second = st.top();
                st.pop(); 

                int s = first + second;
                sum += s;

                st.push(second);
                st.push(first);
                st.push(s);
            }
            else if(it == "D"){
                int first = st.top();

                int s = first * 2;
                sum += s;

                st.push(s);
            }
            else{
                int num = stoi(it);
                sum += num;
                st.push(num);
            }
        }

        return sum;
    }
};