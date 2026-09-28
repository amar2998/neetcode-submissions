class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        while(n!=0){
            int modi=n%2;
            if(modi==1){
                count++;
            }
            n=floor(n/2);
        }
        return count;


    }
};
