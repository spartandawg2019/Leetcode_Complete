class Solution {
public:
bool isHappy(int n) {
unordered_set<int> seen;
while(n != 1) {
int sum = 0;
while(n) {
int digit = n % 10;
sum += digit * digit;
n /= 10;
}
n = sum;
if(seen.count(n)) {
return false;
}
seen.insert(n);
}
return true;
}
};