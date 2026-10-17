#include <vector>
#include <string>

using namespace std;

class Solution {
public:

    string encode(vector<string>& strs) {
        string encodedString = "";
        for (string str : strs) {
            // Fixed: Changed 's' to 'str'
            encodedString += to_string(str.length()) + '#' + str; 
        }
        return encodedString;
    }

    vector<string> decode(string s) {
        vector<string> res; 
        int i = 0;
        
        while (i < s.length()) {
            int j = s.find('#', i);
            
            int len = stoi(s.substr(i, j - i));
            
            i = j + 1;

            res.push_back(s.substr(i, len));
            
            i += len;
        }
        return res; 
    }
};
