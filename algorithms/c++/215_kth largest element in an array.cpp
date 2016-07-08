class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        /*
        std::sort(nums.begin(),nums.end());
        return nums[nums.size()-k];
        */
        
        vector<int> l(k);
        for (int i=0;i<k;++i){
            l[i]=nums[i];
        }
        std::sort(l.begin(), l.end());
        for(int i=k;i<nums.size();++i){
            int n=nums[i];
            int f = -1;
            for (int j=0;j<k;++j){
                if (l[j]>n){
                    break;
                } else {
                    f += 1;
                }
            }
            if (f>=0) {
                for (int m=0;m<f;m++) {
                    l[m]=l[m+1];
                }
                l[f]=n;
            }
        }
        return l[0];
    }
};
