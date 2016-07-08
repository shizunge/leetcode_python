class Solution {
public:
    struct node {
        int num;
        int cur;
    };
    static bool comp(node a, node b){
        int sa = int(sqrt(double(a.num)));
        int sb = int(sqrt(double(a.num)));
        return (a.num-sa*sa)<(b.num-sb*sb);
    }
    int numSquares(int n) {
        /*
        // DP
        static vector<int> dp {0};
        while (dp.size() <= n) {
            int m = dp.size(), squares = INT_MAX;
            for (int i=1; i*i<=m; ++i)
                squares = min(squares, dp[m-i*i] + 1);
            dp.push_back(squares);
        }
        return dp[n];
        */
        int s = int(sqrt(double(n)));
        queue<node> nodes;
        nodes.push(node{n,0});
        // int min = INT_MAX;
        // find a possible min value to reduce the queue size.
        int min = 0;
        int cn = n;
        for (int i=s;i>=1;i--) {
            if (cn>=(i*i)) {
                min += cn/(i*i);
                cn -=(i*i);
            }
        }
        while(!nodes.empty()){
            int cnum = nodes.front().num;
            int cmin = nodes.front().cur;
            nodes.pop();
            for(int i=s;i>=1;i--) {
                if (cnum<i*i) {
                    continue;
                }
                if ((cnum/(i*i))>=min) {
                    continue;
                }
                int r = cnum-i*i;
                int nmin = cmin + 1;
                if (r==0) {
                    // BFS reach the leaf
                    return nmin;
                    if (nmin<min){
                        min=nmin;
                    }
                } else {
                    if (nmin<min) {
                        nodes.push(node{r,nmin});
                    }
                }
            }
        }
        return min;
    }
};
