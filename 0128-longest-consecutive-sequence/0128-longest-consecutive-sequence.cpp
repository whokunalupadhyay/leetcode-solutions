class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }

        int longest = 1;
        unordered_set<int> st;
        for(int i=0; i<n; i++){
            st.insert(nums[i]);
        }

        for(auto it: st){
            if(st.find(it-1) == st.end()){
                // Initializing the count of the current sequence
                int cnt = 1;

                // First element of the current sequence
                int x = it;

                while(st.find(x+1) != st.end()){
                    cnt++;
                    x++;
                }
                // updating the longest subsequence
                longest = max(longest, cnt);
            }
        }

        return longest;
    }
};