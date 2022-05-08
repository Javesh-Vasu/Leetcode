class Solution {
public:
    vector<int> twoSum( vector<int>& nums, int target ) {
        vector<int> ans(2);
        unordered_map<int,int> complements;
        
        for ( int i = 0 ; i < nums.size() ; i++ )
        {
            complements[nums[i]] = i;
        }
        
        for ( int i = 0 ; i < nums.size() ; i++ )
        {
            if ( complements.find(target-nums[i]) != complements.end() && complements[target-nums[i]] != i)
            {
                ans[0] = i;
                ans[1] = complements[target-nums[i]];
                break;
            }
        }
        return ans;
        
    }
};