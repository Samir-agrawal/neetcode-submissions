class Solution {
public:
    bool isPalindrome(string s) {
        string filtered = "";
        for(char &c : s)
        {
            if(c >= 'A' && c <= 'Z') {
                filtered += static_cast<char>(c + 32);
            }
            else if((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
                filtered += c;
            }
        }
        return equal(filtered.begin(),filtered.begin()+filtered.size()/2,filtered.rbegin());
    }
};
