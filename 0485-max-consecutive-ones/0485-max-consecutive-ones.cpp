class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxones = 0;
        int ones = 0;
        for(int i=0;i<nums.size(); i++){
            if(nums[i] != 1){
                maxones = max(maxones,ones);
                cout << maxones;
                ones = 0;
            }
            else{
                ones++;
            }
        }

        return max(maxones,ones);
    }
};