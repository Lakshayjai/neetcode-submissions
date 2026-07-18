class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();

        int k = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] != val){
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};

/*
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        vector<int> tmp;

        for (int num : nums) {
            if (num != val) {
                tmp.push_back(num);
            }
        }

        for (int i = 0; i < tmp.size(); i++) {
            nums[i] = tmp[i];
        }
        
        return tmp.size();

    }
};
*/