class Solution {
public:
    bool check(string &s1, string &s2, int i, int n, int orx, int sum){
        int sum2 = 0, x2 = 1;
        for(int a=i; a<i+n; a++){
            int x = s2[a] - 'a';
            sum2 += x;
            x2 ^= s2[a];
        }
        // cout << sum2 << " " << i << " ";
        // cout << x2 << endl;
        return sum == sum2 && orx == x2;
    }
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if(m < n) return false;
        int orx = 1, sum = 0;
        for(int a=0; a<n; a++){
            int x = s1[a]-'a';
            sum += x;
            orx ^= s1[a];
        }
        // cout << sum << " ";
        // cout << orx << endl;
        for(int i=0; i<m-n+1; i++){
            if(check(s1, s2, i, n, orx, sum)) return true;
        }
        return false;
    }
};
