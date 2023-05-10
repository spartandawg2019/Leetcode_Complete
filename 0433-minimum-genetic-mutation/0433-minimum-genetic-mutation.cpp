class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> genes(bank.begin(), bank.end());
        if (!genes.count(endGene)) return -1;
        queue<string> q{{startGene}};
        int res = 0;
        vector<char> dna{'A', 'C', 'G', 'T'};
        while (!q.empty()) {
            for (int k = q.size(); k > 0; --k) {
                auto gene = q.front(); q.pop();
                if (gene == endGene) return res;
                for (int i = 0; i < gene.size(); ++i) {
                    auto tmp = gene;
                    for (auto c : dna) {
                        tmp[i] = c;
                        if (genes.count(tmp)) {
                            q.emplace(tmp);
                            genes.erase(tmp);
                        }
                    }
                }
            }
            ++res;
        }
        return -1;
    }
};
