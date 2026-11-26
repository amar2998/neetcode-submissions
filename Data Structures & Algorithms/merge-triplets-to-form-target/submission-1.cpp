class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> maxTriplet(3,-1);
        int n=triplets.size();
        for(int i=0;i<n;i++){
            if(triplets[i][0] <= target[0] && triplets[i][1] <=target[1] && triplets[i][2] <= target[2]){
                maxTriplet[0]=max(triplets[i][0],maxTriplet[0]);
                maxTriplet[1]=max(triplets[i][1],maxTriplet[1]);
                maxTriplet[2]=max(triplets[i][2],maxTriplet[2]);
            }
        }
        if(target[0]==maxTriplet[0] && target[1]==maxTriplet[1] && target[2]==maxTriplet[2]){
            return true;
        }
        return false;
    }
};
