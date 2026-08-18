class KthLargest {
public:
    int heapsize;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    KthLargest(int k, vector<int>& nums) {
        
        this->heapsize=k;
        for(int i=0;i<nums.size();i++){
            if(this->minHeap.size() < this->heapsize){
                this->minHeap.push(nums[i]);
            }
            else if(this->minHeap.top() < nums[i]){
                this->minHeap.pop();
                this->minHeap.push(nums[i]);
            }
        }
    }
    
    int add(int val) {
        if(this->minHeap.size() < this->heapsize){
            this->minHeap.push(val);
        }
        else if(this->minHeap.top() < val){
            this->minHeap.pop();
            this->minHeap.push(val);
        }
        return this->minHeap.top();
    }
};
