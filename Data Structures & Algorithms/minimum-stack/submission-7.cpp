class MinStack {
public:
    vector<int> stk;
    vector<int> minQueue;
    MinStack() {
        
    }
    
    void push(int val) {
        if(this->stk.size()==0){
            this->minQueue.push_back(val);
            this->stk.push_back(val);
        }
        else{
            int back=this->minQueue[this->minQueue.size()-1];
            if(back >= val){
                this->minQueue.push_back(val);
                this->stk.push_back(val);
            }else{
                this->stk.push_back(val);
            }

        }
        
    }
    
    void pop() {
        if(this->top() == this->minQueue[this->minQueue.size()-1]){
            this->stk.pop_back();
            this->minQueue.pop_back();

        }
        else{
            this->stk.pop_back();
        }
    }
    
    int top() {
        return this->stk[this->stk.size()-1];
    }
    
    int getMin() {
        return this->minQueue[this->minQueue.size()-1];
    }
};
