class Solution {
    public: string intToRoman(int num) {
        map<int, string, greater<int>> i2r({{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}});
        string ans;
        while (num > 0) {
            for (const auto& e: i2r) {
                if (e.first <= num) {
                    num -= e.first;
                    ans += e.second;
                    break;
                }
            }
        }
        return ans;
        /*
        string s("");
        while (num>0) {
            if(num >= 1000) {
                s += "M";
                num-=1000;
            } else 
            if(num >= 500){
                s += "D";
                num-=500;
            } else 
            if(num >= 100){
                s += "C";
                num-=100;
            } else 
            if(num >= 50){
                s += "L";
                num-=50;
            } else 
            if(num >= 10){
                s += "X";
                num-=10;
            } else 
            if(num >= 5){
                s += "V";
                num-=5;
            } else 
            if(num >= 1) {
                s += "I";
                num-=1;
            }
            int l;
            l = s.size();
            if (l>=5) {
                if (s.substr(l-5,l)=="DCCCC") s.replace(l-5,l,"CM");
            }
            l = s.size();
            if (l>=4) {
                if (s.substr(l-4,l)=="CCCC") s.replace(l-4,l,"CD");
            }
            l = s.size();
            if (l>=5) {
                if (s.substr(l-5,l)=="LXXXX") s.replace(l-5,l,"XC");
            }
            l = s.size();
            if (l>=4) {
                if (s.substr(l-4,l)=="XXXX") s.replace(l-4,l,"XL");
            }
            l = s.size();
            if (l>=5) {
                if (s.substr(l-5,l)=="VIIII") s.replace(l-5,l,"IX");
            }
            l = s.size();
            if (l>=4) {
                if (s.substr(l-4,l)=="IIII") s.replace(l-4,l,"IV");
            }
        }
        return s;
        */
    }
};
