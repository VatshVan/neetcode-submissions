class Solution {
public:

    string encode(vector<string>& strs) {
        string s;

        for (auto& str : strs) {
            for (auto c : str) {
                int a = static_cast<int>(c);

                if (a < 10) s += "00";
                else if (a < 100) s += "0";

                s += to_string(a);
            }

            s += "#";
        }

        return s;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        string curr;

        int i = 0;

        while (i < s.length()) {
            if (s[i] == '#') {
                ans.push_back(curr);
                curr = "";
                i++;
                continue;
            }

            int a = (s[i] - '0') * 100 +
                    (s[i + 1] - '0') * 10 +
                    (s[i + 2] - '0');

            curr += static_cast<char>(a);
            i += 3;
        }

        return ans;
    }
};