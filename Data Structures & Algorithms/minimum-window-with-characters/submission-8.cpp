class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() ==0){
            return "";
        }
        unordered_map<char,int> countT;
        unordered_map<char,int> window;
        for(int i=0;i<t.size();i++){
            countT[t[i]]++;
        }

        int have=0;
        int need=countT.size();
        int resLength=INT_MAX;
        pair<int,int> res={-1,-1};
        int left=0;
        for(int right=0;right<s.size();right++){
            char c=s[right];
            window[c]++;
            if(countT.count(c) && window[c] == countT[c]){
                have++;
            }
            while(have==need){
                //updsate the maxlength
                if(right-left+1 < resLength){
                    resLength=right-left+1;
                    res={left,right};
                }
                window[s[left]]--;
                if(countT.count(s[left]) && window[s[left]] < countT[s[left]]){
                    have--;
                }
                left++;
            }
        }
        return resLength == INT_MAX ? "" :s.substr(res.first,resLength);
    }
};
