class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {

        int mx = *max_element(nums.begin(), nums.end());

        vector<int> freq(mx + 1, 0);

        for (int x : nums)
            freq[x]++;

        vector<long long> gcdCnt(mx + 1, 0);

        for (int g = mx; g >= 1; g--) {

            long long cnt = 0;

            for (int multiple = g; multiple <= mx; multiple += g) {
                cnt += freq[multiple];
                gcdCnt[g] -= gcdCnt[multiple];
            }

            gcdCnt[g] += cnt * (cnt - 1) / 2;
        }

        for (int i = 2; i <= mx; i++)
            gcdCnt[i] += gcdCnt[i - 1];

        vector<int> ans;

        for (long long q : queries) {
            ans.push_back(
                upper_bound(gcdCnt.begin(), gcdCnt.end(), q) - gcdCnt.begin()
            );
        }

        return ans;
    }
};