class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> freq;

        for(int i: nums){
            freq[i]++;
        }

        vector<vector<int>> bucket(nums.size() + 1);

        for(auto &it: freq){
            bucket[it.second].push_back(it.first);
        }

        vector<int> ans;
        for(int i = nums.size(); i>=1; i--){
            for(int ch: bucket[i]){
                if(ans.size() < k){
                    ans.push_back(ch);
                }

            }
        }


        return ans;
        
    }
};