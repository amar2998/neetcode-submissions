class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        vector<int> ans;
        for(int i=0;i<temperatures.size();i++){
            if(i==temperatures.size()-1){
                ans.push_back(0);
                continue;
            }
            
            int j=i+1;
            while(j<temperatures.size() && temperatures[j] <= temperatures[i] && i< temperatures.size() ){
                j++;
            }

            if(j>temperatures.size()-1){
                ans.push_back(0);
                continue;
            }

            
            else{

                int length=j-i;
                ans.push_back(length);
            }

        }
        return ans;
    }
};
