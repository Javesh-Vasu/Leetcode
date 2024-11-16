class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> maxheight(height.size());
        int maxh = 0;
        for ( int i = height.size()-1; i >=0 ; i--){
            maxh = max(maxh,height[i]);
            maxheight[i] = maxh;
        }
        int total_water = 0;
         maxh = 0;
        for ( int i = 0 ; i < height.size(); i++){
            maxh = max(maxh,height[i]);
            int water = min(maxh, maxheight[i]) - height[i];
            if ( water > 0 )
                total_water += water;
                
        }
        return total_water;
    }
};