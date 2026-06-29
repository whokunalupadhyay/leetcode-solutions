class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char,int> need;
        unordered_map<char,int> want;

        for(char ch: s){
            need[ch]++;
        }
        for(char ch: t){
            want[ch]++;
        }

        if(need == want){
            return true;
        }
        return false;
        
    }
};