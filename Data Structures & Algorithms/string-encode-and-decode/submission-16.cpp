class Solution {
public:

    string encode(vector<string>& strs) {
        string ans;
        for(string str:strs){
            ans+=to_string(str.size());
            ans+="#";
            ans+=str;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string>ans;
        string dat;
        int i=0;
        while(i<s.size()){
            int j=i;
            while(s[j]!='#'){
                j++;
            }
            int len=stoi(s.substr(i,j-i));

            string strin=s.substr(j+1,len);
            ans.push_back(strin);
            i=j+1+len;
        }
        return ans;
    }
};
