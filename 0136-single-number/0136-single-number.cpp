class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> list;

        for(int i: nums){
            list[i]++;
        }

        int ans;

        for(auto i: list){
            if((i.second) == 1){
                ans = i.first;
            }
        }

        return ans;
        
    }
};