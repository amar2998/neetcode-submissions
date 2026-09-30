class Solution {
public:
    int reverse(int x) {
        int sign;
        if(x<0){
            sign=-1;
        }
        else{
            sign=1;
        }
        long rev=recursion(abs(x),0)*sign;
        if(rev < INT_MIN || rev > INT_MAX){
            return 0;
        }
        return (int)rev;
    }
    long recursion(int n,long rev){
        if(n==0){
            return rev;
        }
        int digit=n%10;
        rev=rev*10+digit;
        return recursion(n/10,rev);
    }
};
