class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i;
        int flag;
        bool found = false;
        for ( i = nums.size()-1; i >= 1 ; i--){
            if( nums[i] > nums[i-1]){
                found = true;
                break;
            }
        }

        if ( found == false ){
            reverse(nums.begin(),nums.end());
            return;
        }
        flag = i;
        int j = nums.size() -1;
        while ( i < j ){
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j--;
        }
        
        for ( j = flag ; j < nums.size(); j++){
            if ( nums[flag-1] < nums[j]) break;
        }
        int temp = nums[j];
        nums[j] = nums[flag-1];
        nums[flag-1] = temp;
    }
};