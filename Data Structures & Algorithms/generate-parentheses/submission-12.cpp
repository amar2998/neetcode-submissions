class Solution {
public:
    void solution(int  open,int closed,vector<string>& ans,string& demo,int n){
        if(demo.size()==n*2){
            ans.push_back(demo);
            return;
        }
        if(open < n){
            demo.push_back('(');
            solution(open+1,closed,ans,demo,n);
            demo.pop_back();
        }
        if(closed < open){
            demo.push_back(')');
            solution(open,closed+1,ans,demo,n);
            demo.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        // int size=n*2;
        vector<string> ans;
        string demo="";
        solution(0,0,ans,demo,n);
        return ans;
        
    }
};
