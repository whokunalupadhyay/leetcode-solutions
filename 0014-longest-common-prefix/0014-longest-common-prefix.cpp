class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";

        sort(strs.begin(),strs.end());

        string first = strs.front();
        string end = strs.back();

        int i=0;
        while(i<first.size() && i<end.size() && first[i] == end[i]){
            i++;
        }

        return strs[0].substr(0,i);
    }
};