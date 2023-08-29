class Solution {
public:
    
    void makeZero(vector<vector<int>>& matrix , int index, bool isRow){
        if ( isRow ){
            for ( int i = 0 ; i < matrix[0].size(); ++i ){
                matrix[index][i] = 0;
            }
        }
        else{
            for ( int i = 0 ; i < matrix.size(); ++i ){
                matrix[i][index] = 0;
            }
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> rows;
        set<int> columns;
        for ( int i = 0 ; i < matrix.size(); ++i ){
            for ( int j = 0; j < matrix[0].size(); ++j ){
                if ( matrix[i][j] == 0 ){
                    rows.insert(i);
                    columns.insert(j);
                }
            }
        }
        
        for ( auto x : rows ){
            makeZero(matrix, x, true);
        }
        for ( auto x : columns ){
            makeZero(matrix, x , false);
        }
        
        
    }
};