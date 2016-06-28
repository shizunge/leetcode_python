class Solution {
public:
    int nthUglyNumber(int n) {
  vector<int> uglys(1, 1);
  int rt;
  int i=1;
  int p2 = 0, p3 = 0, p5 = 0;  
  while (uglys.size() < n) {  
      //while (i < n) {
    int ugly2 = uglys[p2] * 2, ugly3 = uglys[p3] * 3, ugly5 = uglys[p5] * 5;  
    int min_v = min(ugly2, min(ugly3, ugly5));  
    if (min_v == ugly2) ++p2;  
        if (min_v == ugly3) ++p3;  
        if (min_v == ugly5) ++p5;  
        if (min_v!=rt) i++;
        rt = min_v;
        
        if(min_v != uglys.back()) {  
          // skip duplicate  
          uglys.push_back(min_v);  
        }
        
      }
      //return rt;
      return uglys[n-1];  
    }
};
