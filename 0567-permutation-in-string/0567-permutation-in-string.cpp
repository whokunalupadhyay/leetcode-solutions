class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()){
            return false;
        }

        unordered_map<char,int> need;
        unordered_map<char,int> window;

        for(char ch: s1){
            need[ch]++;
        }

        int left = 0;
        for(int right=0; right < s2.length(); right++){

            window[s2[right]]++;

            // Checking the size of window
            // if it exceed then to remove the left frequency

            if(right - left + 1 > s1.length()){
                
                window[s2[left]]--;

                if(window[s2[left]]== 0){
                    window.erase(s2[left]);
                }

                left++;
            }

            //checking for equal frequency
            if(need == window){
                return true;
            }
        }
        return false;
    }
};