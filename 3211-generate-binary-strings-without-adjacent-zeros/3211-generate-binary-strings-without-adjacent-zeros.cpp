class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> ans;
        if ( n == 0) return ans;
        string dummy(n,'0');
        
        dummy[0] = '1';
        generateStrings( n , 1 , dummy , ans, 1);
        dummy[0] = '0';
        generateStrings( n , 1 , dummy, ans , 0);
        return ans;
    }
    
    void generateStrings(int n , int i, string temp, vector<string>& ans , int prev){
        if ( i >= n ){
            ans.push_back( temp );
            return;
        }
        if ( prev == 0 ){
            temp[i] = '1';
            generateStrings( n , i+1 , temp, ans, 1 );
        }
        else{
            temp[i] = '0';
            generateStrings( n , i +1 , temp , ans, 0);
            temp[i] = '1';
            generateStrings( n , i +1 , temp , ans, 1);
        }
    }
};