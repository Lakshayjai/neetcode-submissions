class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        int i = 0;
        int j = n-1;

        vector<int> res(2);

        while(true){
            if(numbers[i] + numbers[j] > target){
                j--;
            }else if (numbers[i] + numbers[j] < target){
                i++;
            }else{
                res[0] = i+1;
                res[1] = j+1;
                break;
            }
        }
        return res;
    }
};
