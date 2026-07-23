class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> preSumMap;
        int sum = 0;
        int ans = 0;
        preSumMap[0] = 1;

        for(int num: nums){
            sum += num;

            int rem = sum - k;
            if(preSumMap.find(rem) != preSumMap.end()){
                ans += preSumMap[rem];
            }

            preSumMap[sum]++;
        }

        return ans;
    }
};