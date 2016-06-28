class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size()==1) {
            return triangle[0][0];
        }
        vector<int> rt_row;
        for (vector<int>row : triangle) {
            vector<int> rt_row1{0};
            vector<int> rt_row2{0};
            if (rt_row.size()==0){
                rt_row.insert(rt_row.begin(),row[0]);
            } else {
                rt_row1 = rt_row;
                rt_row2 = rt_row;
                rt_row1.insert(rt_row1.begin(), 0);
                rt_row2.insert(rt_row2.end(), 0);
            }
            rt_row = row;
            for (int i=1;i<row.size()-1;++i) {
                if (rt_row1[i]<rt_row2[i]) {
                    rt_row[i]+=rt_row1[i];
                } else {
                    rt_row[i]+=rt_row2[i];
                }
            }
            rt_row[0]+=rt_row2[0];
            rt_row.back()+=rt_row1.back();
        }
        int min = rt_row[0];
        for (int v : rt_row){
            if(v<min){
                min=v;
            }
        }
        return min;
    }
};
