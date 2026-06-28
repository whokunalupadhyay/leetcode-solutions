class Solution {
public:
    string removeDuplicates(string s) {

        stack<char> st;

        string new_s;

        int i=0;
        while(i < s.length()){

            char value = s[i];
            
            if(!st.empty() && st.top() == value){
                st.pop();
                i++;
            }
            else{
                st.push(s[i]);
                i++;
            }
        }
        while(!st.empty()){
            new_s += st.top();
            st.pop();
        }
        reverse(new_s.begin(),new_s.end());
        return new_s;

        
    }
};