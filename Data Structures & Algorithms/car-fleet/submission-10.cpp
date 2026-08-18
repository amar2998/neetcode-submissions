class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> dummyArray;
        for(int i=0;i<position.size();i++){
            dummyArray.push_back({position[i],speed[i]});
        }
        sort(dummyArray.begin(),dummyArray.end(),[](pair<int,int>&a,pair<int,int>&b){
            return a.first > b.first;
        });
        int fleetCount=0;
        double maxTime=0;
        vector<double> timeArray;
        for(auto arr : dummyArray){
            int distance=target - arr.first;
            double time=(double)distance / arr.second;
            if(time > maxTime){
                fleetCount++;
                maxTime=time;
            }
            
        }
           
        return fleetCount;
    }
};
