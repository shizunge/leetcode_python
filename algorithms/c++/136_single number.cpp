class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int rt = 0;
        for(auto it = nums.begin();it!=nums.end();it++) {
            rt ^= *it;
        }
        return rt;
    }
};
