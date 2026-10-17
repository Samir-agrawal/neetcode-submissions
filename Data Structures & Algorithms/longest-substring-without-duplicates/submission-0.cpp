class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> uniques;
        int l = 0, r = 0;
        int maxLen = 0;
        while(r<s.length())
        {
            if(uniques.contains(s[r])) 
            {
                while(s[l]!=s[r]){
                    uniques.erase(s[l]);
                    l++;
                }
                l++;
            }
            else uniques.insert(s[r]);
            maxLen = max(maxLen,r-l+1);
            r++;
        }
        
        return maxLen;
    }
};
