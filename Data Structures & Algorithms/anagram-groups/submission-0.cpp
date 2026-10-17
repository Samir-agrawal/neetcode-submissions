class Solution {
private:
    string getStringHash(string str){
        int hash[26] = {0};
        for(char c:str){
            hash[c-'a']++;
        }
        string key = "";
        for(int i=0;i<26;i++)
        {
            key += ('a' + i);
            key += hash[i];
        }
        return key;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> anagrams;
        for(int i=0;i<strs.size();i++)
        {
            string hashKey = getStringHash(strs[i]);
            anagrams[hashKey].push_back(strs[i]);
        }
        vector<vector<string>> res;
        for(auto p : anagrams){
            string key = p.first;
            vector<string> anagramStrings = p.second;
            res.push_back(anagramStrings);
        }
        return res;
    }
};
