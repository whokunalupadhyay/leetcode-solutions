class Solution {
public:
    string removeOuterParentheses(string s) {
        int i=0;
        string ans;
        int depth = 0;
        while(i < s.length()){
            if(s[i] == '('){
                if(depth > 0){
                    ans.push_back(s[i]);
                }
                depth++;
            }
            else{
                depth--;
                if(depth > 0){
                    ans.push_back(s[i]);
                }

            }
            i++;
        }

        return ans;
    }
};