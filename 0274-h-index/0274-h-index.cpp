class Solution {
public:
int hIndex(vector<int>& citations) {
int n = citations.size();
vector<int> bucket(n + 1, 0);
for (int c : citations) {
if (c >= n) {
bucket[n]++;
} else {
bucket[c]++;
}
}
int count = 0;
for (int i = n; i >= 0; i--) {
count += bucket[i];
if (count >= i) {
return i;
}
}
return 0;
}
};