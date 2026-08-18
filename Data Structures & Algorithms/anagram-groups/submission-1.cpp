#include<unordered_map>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> vmap;
        for(string str:strs){
            int arr [26]={0};
            for(int i=0;i<str.size();i++){
                arr[str[i]-'a']++;

            }
            string key;
            for(int i=0;i<26;i++){
                key+='#';
                key+=to_string(arr[i]);
            }
            vmap[key].push_back(str);
        }   
        vector<vector<string>> ans;
        for(auto [key,value]:vmap){
            sort(value.begin(),value.end());
            ans.push_back(value);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
