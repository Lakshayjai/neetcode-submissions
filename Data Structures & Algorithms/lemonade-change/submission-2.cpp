class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five_cnt = 0; // 1
        int ten_cnt = 0; // 0
        int twenty_cnt = 0; //

        for(int i = 0; i < bills.size(); i++){  //1
            if(bills[i] == 5){
                five_cnt++;
            } else if(bills[i] == 10){
                ten_cnt++;
                five_cnt--;
            } else{
                if(ten_cnt >= 1 and five_cnt >= 1){
                    ten_cnt--;
                    five_cnt--;
                }
                else if(ten_cnt == 0 and five_cnt >= 3){
                    five_cnt -= 3;
                }else{
                    return false;
                }
            }

            if(five_cnt < 0 or ten_cnt < 0 or twenty_cnt < 0) return false;
        }

        return true;
    }
};