class Solution {
public:
    bool isUgly(int num) {
        if (num==0) {
            return false;
        }
        int rt = num;
        while (rt%5==0) {
            rt /= 5;
        }
        while (rt%3==0) {
            rt /= 3;
        }
        while (rt%2==0) {
            rt /= 2;
        }
        return (rt==1);
    }
};
