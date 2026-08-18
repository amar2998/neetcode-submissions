class Solution {
public:
    
    void assignValues(unordered_map<char,vector<char>>& mobileKey ){
        mobileKey['2']={'a','b','c'};
        mobileKey['3']={'d','e','f'};
        mobileKey['4']={'g','h','i'};
        mobileKey['5']={'j','k','l'};
        mobileKey['6']={'m','n','o'};
        mobileKey['7']={'p','q','r','s'};
        mobileKey['8']={'t','u','v'};
        mobileKey['9']={'w','x','y','z'};
        

    } 

    void backtrack(string &digits,vector<string>& ans,string &path,unordered_map<char,vector<char>>& mobileKey,int index){
        if(index==digits.size()){
            ans.push_back(path);
            return;
        }
        vector<char> element=mobileKey[digits[index]];
        for(auto ele:element){
            path.push_back(ele);
            backtrack(digits,ans,path,mobileKey,index+1);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }
        unordered_map<char,vector<char>> mobileKey;
        assignValues(mobileKey);
        vector<string> ans;
        string path="";
        int index=0;
        backtrack(digits,ans,path,mobileKey,index);
        return ans;


    }
};
