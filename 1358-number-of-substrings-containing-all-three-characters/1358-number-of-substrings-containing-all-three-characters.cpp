class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> freq(3, 0);
        int left = 0;
        int have = 0;
        int ans = 0;
        int n = s.size();

        for (int right = 0; right < n; right++) {
            if (freq[s[right] - 'a'] == 0)
                have++;
            freq[s[right] - 'a']++;

            while (have == 3) {
                ans += n - right;

                freq[s[left] - 'a']--;
                if (freq[s[left] - 'a'] == 0)
                    have--;

                left++;
            }
        }

        return ans;
    }
};