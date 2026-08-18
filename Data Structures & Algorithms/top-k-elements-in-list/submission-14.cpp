#include<stack>
#include<queue>
class Solution {
public:
    static bool sortByFrequenty(const pair<int,int>&q1,const pair<int,int>&q2){
        if(q1.second==q2.second){
            return q1.first < q2.first;
        }
        return q1.second > q2.second;
    }
    // vector<int> topKFrequent(vector<int>& nums, int k) {
    //     vector <pair<int,int>> stk;
    //     unordered_map<int,int> hashmap;
    //     for(int i=0;i<nums.size();i++){
    //         hashmap[nums[i]]++;

    //     }

    //     for(auto [key,value]:hashmap){
    //         stk.push_back({key,value});
    //     }
    //     sort(stk.begin(),stk.end(),sortByFrequenty);
    //     vector<int> ans;
    //     for(int i=0;i<k;i++){
    //         ans.push_back(stk[i].first);

    //     }
    //     return ans;
    // }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> hashmap;
        for(int i=0;i<nums.size();i++){
            hashmap[nums[i]]++;

        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minheap;
        for(auto [key,value]:hashmap){
            minheap.push({value,key});
            if(minheap.size()>k){
                minheap.pop();
            }
        }
        vector<int> ans;
        while(!minheap.empty()){
            pair<int,int> data=minheap.top();
            ans.push_back(data.second);
            minheap.pop();
        }
        return ans;
    }
};
