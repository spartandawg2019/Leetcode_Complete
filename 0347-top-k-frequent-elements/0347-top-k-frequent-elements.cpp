class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Create a hashmap to keep track of the frequency of each element in the input array
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        // Create a priority queue to store the elements sorted by their frequency in descending order
        priority_queue<pair<int, int>> pq;
        for (auto f : freq) {
            pq.push({f.second, f.first});
        }
        // Create a list to store the k most frequent elements
        vector<int> res;
        // Iterate through the priority queue and add the first k elements to the list
        for (int i = 0; i < k; i++) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        // Return the list
        return res;
    }
};
