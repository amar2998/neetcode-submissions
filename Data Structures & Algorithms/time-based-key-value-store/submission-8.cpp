class TimeMap {
public:
     unordered_map<string,vector<pair<string,int>>> timeMap;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timeMap[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        vector<pair<string,int>> arr=timeMap[key];
        int left=0;
        int right=arr.size()-1;
        string ans="";
        while(left <=right){
            int mid=left+(right-left)/2;
            if(arr[mid].second <= timestamp){
                ans=arr[mid].first;
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return ans;
    }
};
