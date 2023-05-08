class Solution {
public:
vector<string> letterCombinations(string digits) {
vector<string> res;
if(digits.empty()) return res;
unordered_map<char, string> phone = {{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
res.push_back("");
for(char digit : digits) {
vector<string> temp;
for(char c : phone[digit])
for(string s : res)
temp.push_back(s + c);
res = temp;
}
return res;
}
};