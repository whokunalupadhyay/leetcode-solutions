class Solution {
public:
    class Fenwick {
    public:
        vector<int> bit;

        Fenwick(int n) {
            bit.assign(n + 1, 0);
        }

        void update(int idx, int val) {
            while (idx < bit.size()) {
                bit[idx] += val;
                idx += idx & -idx;
            }
        }

        int query(int idx) {
            int sum = 0;
            while (idx > 0) {
                sum += bit[idx];
                idx -= idx & -idx;
            }
            return sum;
        }
    };

    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        // Prefix sums lie in [-n, n]
        int offset = n + 1;
        Fenwick ft(2 * n + 5);

        long long ans = 0;
        int prefix = 0;

        // Initial prefix sum = 0
        ft.update(offset, 1);

        for (int x : nums) {
            if (x == target)
                prefix++;
            else
                prefix--;

            // Count previous prefix sums < current prefix
            ans += ft.query(prefix + offset - 1);

            // Insert current prefix
            ft.update(prefix + offset, 1);
        }

        return ans;
    }
};