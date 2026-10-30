class Solution {
public:
    // int minDistance(string word1, string word2) {
    //     if(word1== ""){
    //         return word2.size();
    //     }
    //     if(word2==""){
    //         return word1.size();
    //     }
    //     if(word1[0]==word2[0]){
    //         return minDistance(word1.substr(1),word2.substr(1));
    //     }

    //     int insert=minDistance(word1,word2.substr(1));
    //     int del=minDistance(word1.substr(1),word2);
    //     int replace=minDistance(word1.substr(1),word2.substr(1));
    //     return 1+ min(insert,min(del,replace));

    // }
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        for(int i=0;i<m+1;i++){
            dp[i][0]=i;
        }
        for(int i=0;i<n+1;i++){
            dp[0][i]=i;
        }

        for( int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    int insert=dp[i][j-1]+1;
                    int delet=dp[i-1][j]+1;
                    int update=dp[i-1][j-1]+1;

                    dp[i][j]=min(insert,min(delet,update));
                }
            }
        }
        return dp[m][n];

        // int i=m;
        // int j=n;
        // int operation=0;
        // while(i>0 || j>0){
        //     if(i > 0 && j>0 && word1[i-1]==word2[j-1]){
        //         operation++;
        //         i--;
        //         j--;
        //     }
        //     else{
        //         if(i >0 && j >0 && dp[i][j] == dp[i-1][j-1]+1){
        //             operation++;
        //             i--;
        //             j--;
        //         }
        //         else if(i>0 && dp[i][j]==dp[i-1][j]+1){
        //             i--;
        //             operation++;
        //         }
        //         else if(j>0 && dp[i][j]==dp[i][j-1]+1){
        //             operation++;
        //             j--;
        //         }
        //     }

        // }
        // return operation;
        
      
    }
};
