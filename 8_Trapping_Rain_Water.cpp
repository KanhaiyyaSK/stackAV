
//https://leetcode.com/problems/trapping-rain-water/description/

class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();

        vector<int>maxR(size);
        vector<int>maxL(size);

        maxL[0] = height[0];
        for(int i=1; i<size; i++){
            maxL[i] = max(height[i],maxL[i-1]);
        }

        maxR[size-1] = height[size-1];
        for(int i=size-2; i>=0; i--){
            maxR[i] = max(height[i], maxR[i+1]);
        }

        vector<int>water(size);
        for(int i=0; i<size; i++){
            water[i] = min(maxR[i],maxL[i]) - height[i];
        }

        int ans = 0;

        for(int i=0; i<size; i++){
            ans+=water[i];
        }

        return ans;


    }
};