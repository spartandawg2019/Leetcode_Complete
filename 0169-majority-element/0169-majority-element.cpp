class Solution {
public:
int majorityElement(vector<int>& nums) {
unordered_map<int, int> count;
int n = nums.size();
for(int i = 0; i < n; i++) {
count[nums[i]]++;
}
for(auto i : count) {
if(i.second > n / 2) {
return i.first;
}
}
return -1; // added a return statement as the function needs to return something
}
};