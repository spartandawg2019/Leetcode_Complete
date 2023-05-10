class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> product(num1.length() + num2.length(), 0);
        int m = num1.length(), n = num2.length();

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int p1 = i + j, p2 = i + j + 1;
                int sum = mul + product[p2];

                product[p1] += sum / 10;
                product[p2] = sum % 10;
            }
        }

        string res = "";
        for (int i = 0; i < product.size(); i++) {
            if (!(res.length() == 0 && product[i] == 0)) {
                res += to_string(product[i]);
            }
        }

        return res.length() == 0 ? "0" : res;
    }
};
