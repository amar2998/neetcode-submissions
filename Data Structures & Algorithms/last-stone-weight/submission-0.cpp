class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for(int i=0;i<stones.size();i++){
            maxHeap.push(stones[i]);
        }

        while(maxHeap.size()>1){
            int largest=maxHeap.top();
            maxHeap.pop();
            int secondlargest=maxHeap.top();
            maxHeap.pop();
            if(largest > secondlargest){
                int ele=largest-secondlargest;
                maxHeap.push(ele);
            }
        }

        return maxHeap.size() >0?maxHeap.top():0;
    }
};
