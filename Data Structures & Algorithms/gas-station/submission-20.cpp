class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=cost.size();
        int start=n-1;
        int end=0;
        int tank=gas[start]-cost[start];
        while(start > end){
            if(tank<0){
                start--;
                tank=tank+(gas[start]-cost[start]);
            }
            else{
                tank=tank+(gas[end]-cost[end]);
                end++;
            }
        }
        if(tank <0){
            return -1;
        }
        else{
            return start;
        }
    }
};