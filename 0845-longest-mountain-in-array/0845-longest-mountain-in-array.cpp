class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int maxLength = 0;
        int flag = 0;
        int length = 0;
        for ( int i = 0 ; i < arr.size()-1; i++){
            if ( arr[i] < arr[i+1] ){
                if ( flag == 0 ){
                    length++;
                }
                else if ( flag == 1){
                    maxLength = max(maxLength,length+1);
                    length = 0;
                    flag = 0;
                    i--;
                }
            }
            
            else if ( arr[i] > arr[i+1]){
                if ( flag == 0 && length != 0 ){
                    flag = 1;
                    length++;
                }
                else if ( flag == 1 ){
                    length++;
                }
            }
            else{
                if ( flag == 1 ){
                    maxLength = max(maxLength,length+1);
                }
                flag = 0;
                length = 0;
            }
        }
        
        if ( flag == 1 ){
            maxLength = max(maxLength,length+1);
        }
        return maxLength;
    }
};