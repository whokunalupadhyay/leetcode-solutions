class Solution {
public:
    string defangIPaddr(string address) {
        string n;
        for(int i=0; i<address.length(); i++){
            if(address[i] == '.'){
                n.push_back('[');
                n.push_back('.');
                n.push_back(']');
            }
            else{
                n.push_back(address[i]);
            }
        }

        return n;
        
    }
};