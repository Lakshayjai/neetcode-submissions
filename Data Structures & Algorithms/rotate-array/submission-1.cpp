class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        int n= arr.size();
        k=k%n;
        
        //1. Reverse the entire arr(0...n-1)
        int i=0;
        int j=n-1;

        while (i<j){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }

        //2. Reverse 1st k values arr(0...k-1)
        i=0;
        j=k-1;

        while (i<j){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
        
        //3. Reverse last n-k values arr(k...n-1)
        i=k;
        j=n-1;

        while (i<j){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
};