class Solution {
public:
    string removeOuterParentheses(string s) {

        string ans;
        int i = 0;
        int depth = 0;
        while(i < s.length()){
            if(s[i] == '('){
                if(depth > 0){
                    ans.push_back(s[i]);
                    depth++;
                }
                else{
                    depth++;
                }
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