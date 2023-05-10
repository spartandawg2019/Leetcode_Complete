class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r=0, w=0; // label the end of different colors;
        for(int num: nums){
            if(num == 0) { 
                nums[w++]=1; 
                nums[r++]=0; 
            } 
            else if(num==1) 
                nums[w++]=1;
        }
        for (int i = w; i < nums.size();++i)
            nums[i] = 2;
    }
};
