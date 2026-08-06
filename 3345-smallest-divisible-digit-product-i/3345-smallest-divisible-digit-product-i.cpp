class Solution {
public:
    int DigitProduct(int num){
        int ans = 1;
        while(num > 0){
            ans = ans * (num % 10);
            num = num /10;
        }

        return ans;
    }
    int smallestNumber(int n, int t) {
        if(DigitProduct(n) % t == 0){
            return n;
        }

        for(int i=0; i<10; i++){
            n++;
            if(DigitProduct(n) % t == 0){
                return n;
            }
        }

        return -1;
    }
};