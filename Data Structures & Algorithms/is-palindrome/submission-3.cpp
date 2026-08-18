class Solution {
public:
    string filter(string & s){
        string ans;
        for(int i=0;i<s.size();i++){
            if((s[i] >='a' && s[i]<='z' ) || (s[i] >='A' && s[i] <='Z') || (s[i]>='0' && s[i]<='9')){

                ans+=tolower(s[i]);
            }
        }
        return ans;
    }
    bool isPalindrome(string s) {
        string str=filter(s);
        
        int left=0;
        int right=str.size()-1;
        while(left<right){
            if(str[left]!=str[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
        
    }
};
