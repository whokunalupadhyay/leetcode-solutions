class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxcount = 0;
        for(int i=0; i<sentences.size(); i++){
            string str = sentences[i];
            int cont = count(str.begin(),str.end(),' ') + 1;
            
            maxcount = max(maxcount, cont);
            
        }

        return maxcount;
    }
};