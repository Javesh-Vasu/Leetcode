class Solution {
public:
    
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length()+1 , vector<int>(text2.length()+1,-1));
        int i = 0; 
        int j = 0;
        return ans( text1, text2 ,i , j ,dp);
    }
    
    int ans(string& text1, string &text2, int i, int j ,vector<vector<int>>& dp){
        if ( i >= text1.length( ) || j >= text2.length( ) ) return 0;
        if ( dp[i][j] != -1 ) return dp[i][j];
        if ( text1[i] == text2[j]) 
        {
            
            int x = ans(text1 , text2 , i+1, j+1,dp);
            dp[i+1][j+1] = x;
            return 1 + x;
        }
        int x = ans(text1 , text2 , i+1, j, dp);
        int y = ans(text1 , text2 , i, j+1,dp);
        dp[i+1][j] = x;
        dp[i][j+1] = y;
        return max(x , y );
    }
};