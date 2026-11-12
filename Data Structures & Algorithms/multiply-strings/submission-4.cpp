class Solution {
public:
    
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        int m = num1.size(), n = num2.size();
        vector<int> res(m + n, 0);

        for (int i = m - 1; i >= 0; --i)
            for (int j = n - 1; j >= 0; --j) {
                res[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
            }

        for (int i = m + n - 1; i > 0; --i) {
            res[i - 1] += res[i] / 10;
            res[i] %= 10;
        }

        int start = 0;
        while (start < (int)res.size() && res[start] == 0) start++;
        string ans;
        for (int i = start; i < (int)res.size(); ++i)
            ans += (char)('0' + res[i]);
        return ans;
    }
};
