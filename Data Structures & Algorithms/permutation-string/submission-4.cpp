class Solution {
public:
    bool isEqual(vector<int > freq1,vector<int> windFreq){
        for(int i=0;i<26;i++){
            if(freq1[i]!=windFreq[i]){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        vector<int > freq(26,0);
        for(int i=0;i<s1.size();i++){
            freq[s1[i]-'a']++;
        }
        int windowSize=s1.size();
        for(int i=0;i<s2.size();i++){
            vector<int> windFreq(26,0);
            int windowIndex=0;
            int idx=i;
            while(windowIndex < windowSize && idx < s2.size()){
                windFreq[s2[idx]-'a']++;
                windowIndex++;
                idx++;
            }
            if(isEqual(freq,windFreq)){
                return true;
            }
        }
        return false;
        
    }
};
