class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char,int> freq;

        for(char ch: s){
            freq[ch]++;
        }

        vector<vector<char>> bucket(s.size() + 1);

        for(auto &it: freq){
            bucket[it.second].push_back(it.first);
        }

        string ans;
        for(int i=s.size(); i>=1; i--){
            for(char ch: bucket[i]){
                ans.append(i, ch);
            }
        }
        

        return ans;
    }
};