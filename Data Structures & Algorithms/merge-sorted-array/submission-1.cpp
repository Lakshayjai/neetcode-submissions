class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        int j = 0;
        int k = 0;

        vector<int> temp (m+n);

        while(i < m and j < n){
            if(nums1[i] > nums2[j]){
                temp[k++] = nums2[j];
                j++;
            }else{
                temp[k++] = nums1[i];
                i++;
            }
        }

        while(i < m){
            temp[k++] = nums1[i++];
        }
        while(j < n){
            temp[k++] = nums2[j++];
        }

        nums1 = temp;

    }
};