class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;
        vector<int> temp;
        int i = 1;

        temp.push_back(nums[0]);

        while(i < nums.size()){
            if(nums[i] != nums[i-1]){
                temp.push_back(nums[i]);
                k++;
            }
            i++;

        }

        nums = temp;

        return k;
    }
};