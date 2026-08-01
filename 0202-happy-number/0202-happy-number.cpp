class Solution {
public:
    int square(int num){
        int sq = 0;
        while(num > 0){
            int ans = num % 10;
            sq += ans*ans;
            num = num / 10;
        }

        return sq;
    }
    bool isHappy(int n) {
        if(n == 1){
            return true;
        }
        unordered_map<int,int> mp;

        while(n != 1){
            int sq = square(n);
            if(mp.find(sq) != mp.end()){
                return false;
            }
            mp[sq]++;
            if(sq == 1){
                return true;
            }
            n = sq;
        }

        return false;
    }
};