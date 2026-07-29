class Solution {
public:
    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;
        vector<int> half(26);
        char middle = 0;
        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            if (freq[i] % 2)
                middle = char('a' + i);
        }
        int len = s.size() / 2;
        auto combinations = [&](int n, int r) -> long long {
            r = min(r, n - r);
            long long ans = 1;
            for (int i = 1; i <= r; i++) {
                ans = ans * (n - r + i) / i;
                if (ans >= k)
                    return k;
            }
            return ans;
        };
        auto countWays = [&](vector<int>& cnt) -> long long {
            int remaining = 0;
            for (int x : cnt)
                remaining += x;
            long long ways = 1;
            for (int i = 0; i < 26; i++) {
                if (cnt[i] == 0)
                    continue;
                ways *= combinations(remaining, cnt[i]);
                if (ways >= k)
                    return k;
                remaining -= cnt[i];
            }
            return ways;
        };
        if (countWays(half) < k)
            return "";
        string left;
        for (int pos = 0; pos < len; pos++) {
            for (int c = 0; c < 26; c++) {
                if (half[c] == 0)
                    continue;
                half[c]--;
                long long ways = countWays(half);
                if (k > ways) {
                    k -= ways;
                    half[c]++;
                }
                else {
                    left += char('a' + c);
                    break;
                }
            }
        }
        string right = left;
        reverse(right.begin(), right.end());
        if (middle)
            return left + middle + right;
        return left + right;
    }
};