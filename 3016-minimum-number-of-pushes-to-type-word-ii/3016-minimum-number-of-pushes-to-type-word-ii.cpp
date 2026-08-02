class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26,0);

        for(int i=0;i<word.length();i++){
            freq[word[i]-'a']++;
        }
        sort(freq.begin(),freq.end(),greater<int>());

        int ans=0;
        int count=0;

        for(int i=0;i<26;i++){
            count=(i/8)+1;
            ans+=(freq[i]*count);
        }
        return ans;
    }
};