class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int right=0;
        int maxLength=0;
        unordered_map<char,int> charMap;
        while(right < s.size()){
            charMap[s[right]]++;
            if(charMap[s[right]] > 1){
                while(charMap[s[right]] >1){
                    charMap[s[left]]--;
                    left++;
                }
            }
            int length=right-left+1;
            maxLength=max(length,maxLength);
            right++;

        }
        return maxLength;

    }
};
