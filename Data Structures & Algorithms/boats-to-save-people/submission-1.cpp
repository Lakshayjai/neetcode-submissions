class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        int i = 0;
        int j = n-1;

        int cnt = 0;

        sort(people.begin(), people.end());

        while(i <= j){
            if(i == j){

                if(people[i] < limit){
                    cnt++;
                }else{
                    if(people[i] % limit == 0){
                        cnt += people[i] / limit;
                    }else{
                        int val = (people[i] / limit) + 1;
                        cnt += val;
                    }
                }
                break;

            }else{
                cnt++;
                if(people[i] + people[j] > limit){
                    j--;
                }else{
                    i++;
                    j--;
                }
            }
        }

        return cnt;
    }
};