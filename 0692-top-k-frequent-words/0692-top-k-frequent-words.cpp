class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> freq;

        for(string str: words){
            freq[str]++;
        }

        vector<vector<string>> bucket(words.size() + 1);

        for(auto &it: freq){
            bucket[it.second].push_back(it.first);
        }

        for (auto &b : bucket){
            sort(b.begin(), b.end());
        }

        vector<string> ans;

        for(int i=words.size(); i>=1; i--){
            for(string ch: bucket[i]){
                if(ans.size() < k){
                    ans.push_back(ch);
                }
            }
        }

        return ans;
    }
};