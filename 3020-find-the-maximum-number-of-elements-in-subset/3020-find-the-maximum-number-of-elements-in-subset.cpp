class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;

        for (int x : nums)
            freq[x]++;

        int ans = 1;

        if (freq.count(1))
            ans = (freq[1] & 1) ? freq[1] : freq[1] - 1;

        for (auto &[x, cnt] : freq) {
            if (x == 1) continue;

            long long cur = x;
            int len = 0;

            while (true) {
                auto it = freq.find(cur);
                if (it == freq.end() || it->second < 2) break;

                len += 2;
                cur = cur * cur;
            }

            auto it = freq.find(cur);
            if (it != freq.end() && it->second >= 1)
                len++;
            else
                len--;

            ans = max(ans, len);
        }

        return ans;
    }
};