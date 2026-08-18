class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();      
        vector<int> ans(n,0);
        stack<int> stk;
        for(int i=0;i<n;i++){

            while(!stk.empty() && temperatures[stk.top()] <temperatures[i] ){
                int index=stk.top();
                stk.pop();
                ans[index]=i-index;
            }
            stk.push(i);
        }
        return ans;



        // for(int i=0;i<temperatures.size();i++){
        //     if(i==temperatures.size()-1){
        //         ans.push_back(0);
        //         continue;
        //     }
            
        //     int j=i+1;
        //     while(j<temperatures.size() && temperatures[j] <= temperatures[i] && i< temperatures.size() ){
        //         j++;
        //     }

        //     if(j>temperatures.size()-1){
        //         ans.push_back(0);
        //         continue;
        //     }

            
        //     else{

        //         int length=j-i;
        //         ans.push_back(length);
        //     }

        // }




        // stack<int> stk;
        // for(int i=0;i<temperatures.size();i++){
        //     while(!stk.empty() &&
        //           temperatures[stk.top()] < temperatures[i]) {

        //         int idx = stk.top();
        //         stk.pop();

        //         ans[idx] = i - idx;
        //     }

        //     stk.push(i);
        // }
        // return ans;
    }
};
