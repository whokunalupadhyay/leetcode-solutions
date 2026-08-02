class Solution {
public:
    int minimumPushes(string word) {
        int remaning=word.length();
        int count=1;
        int ans=0;

        while(remaning>0){
            int take=min(remaning,8);
            remaning-=take;
            ans=ans+(take*count);
            count++;


        }
        return ans;
    }
};