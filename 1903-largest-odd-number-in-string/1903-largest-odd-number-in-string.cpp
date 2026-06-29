class Solution {
public:
    string largestOddNumber(string num) {
        int right = num.length() - 1;
        int digit = num[right] - '0';
        if(digit%2 != 0){
            return num;
        }
        right--;
        while(right >= 0){
            if((num[right] - '0') % 2 != 0){
                return num.substr(0,right+1);
            }
            right--;

        }
        return "";
    }
};