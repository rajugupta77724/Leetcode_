class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX=2048;
        vector<bool> pairXor(MAXX, false);
        vector<bool>ans(MAXX,false);
        int n = nums.size();
        for (int j=0;j<n;j++) {
            for (int k=j;k<n;k++) {
                pairXor[nums[j]^nums[k]]=true;
            }
        }
        for (int i=0;i<n;i++){
            for (int x= 0; x < MAXX; x++) {
                if (pairXor[x]){
                    ans[nums[i]^x]=true;
                }
            }
        }
        int res=0;
        for(bool x:ans)
            if (x)res++;

        return res;
    }
};