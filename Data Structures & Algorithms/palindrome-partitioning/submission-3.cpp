class Solution {
public:

    bool isPalindrom(string &s,int start,int end){
        while(start < end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    void backtrack(vector<vector<string>>& ans,vector<string>& path,int start,string &s){
        if(start==s.size()){
            ans.push_back(path);
            return;
        }
        else{
            for(int end=start;end<s.size();end++){
                if(isPalindrom(s,start,end)){
                    path.push_back(s.substr(start,end-start+1));
                    backtrack(ans,path,end+1,s);
                    path.pop_back();
                }
            }
        }

    }
    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> path;
        int index=0;
        backtrack(ans,path,index,s);
        return ans;
        
    }
};
