class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        int max = *max_element(nums.begin(),nums.end());
        int min = *min_element(nums.begin(),nums.end());
        unordered_set<int> st;
        vector<int> ans;

        for(int x: nums){
            st.insert(x);
        }

        for(int i=min; i<max; i++){
            if(st.find(i) == st.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};