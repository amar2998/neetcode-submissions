class Solution {
public:

    int evalRPN(vector<string>& tokens) {
        stack<string> stk;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/" ){
                int data2=stoi(stk.top());
                stk.pop();
                int data1=stoi(stk.top());
                stk.pop();
                if(tokens[i]=="+"){

                    int sum=data1+data2;
                    stk.push(to_string(sum));
                }
                else if(tokens[i]=="-"){
                    int sub=data1-data2;
                    stk.push(to_string(sub));
                }
                else if(tokens[i]=="*"){
                    int mul=data1*data2;
                    stk.push(to_string(mul));
                }
                else if(tokens[i]=="/"){
                    int div=data1/data2;
                    stk.push(to_string(div));
                }
            }
            else{
                stk.push(tokens[i]);
            }
        }
        return stoi(stk.top());
    }
};
