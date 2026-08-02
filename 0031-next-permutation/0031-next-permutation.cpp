class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = -1;
        int n = nums.size();

        //find the breaking point
        for(int i=n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                index = i;
                break;
            }
        }

        if(index == -1){
            reverse(nums.begin(),nums.end());
            return;
        }

        //swap with the index
        for(int i=n-1; i>=0; i--){
            if(nums[i] > nums[index]){
                swap(nums[i],nums[index]);
                break;
            }
        }

        // sorting the remaining array
        reverse(nums.begin() + index + 1, nums.end());

    }
};