class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0;
        int n = chars.size();
        int write = 0;
        while(i < n){
            int j = i;
            while(j < n && chars[j] == chars[i]){
                j++;
            }

            chars[write] = chars[i];
            write++;

            int count = j - i;

            // code for the count if needed;
            if(count > 1){
                string freq = to_string(count);
                for(char digit: freq){
                    chars[write] = digit;
                    write++;
                }
            }

            i = j;
        }

        return write;
    }
};