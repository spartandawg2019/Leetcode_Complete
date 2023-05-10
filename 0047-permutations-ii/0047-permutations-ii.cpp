#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        set<vector<int>> permutations;
        sort(nums.begin(), nums.end());
        do {
            permutations.insert(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        for (auto perm : permutations) {
            result.push_back(perm);
        }
        return result;
    }
};
