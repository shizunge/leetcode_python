class Solution {
public:
    int myAtoi(string str) {
    if (str.size()==0){
        return 0;
    }
    
    int ret=0;
    int offset = 0;
    while(str[offset]==' ') {
        offset++;
    }
    
    bool neg=false;
    if (str[offset]=='-' || str[offset]=='+') {
        neg = (str[offset]=='-') ;
        offset++;
    }
   // cout<<offset<<endl;
    while(str[offset]>='0' && str[offset]<='9') {
        // cout<<"tata"<<endl;
        int digit = (str[offset]-'0');
        if(neg){
            if( -ret < (INT_MIN + digit)/10 ) {
                return INT_MIN;
            }
        }else{
            if( ret > (INT_MAX - digit) /10 ) {
                return INT_MAX;
            }
        }
        offset++;

        ret = 10*ret + digit ;
    }
    
    return neg?-ret:ret;
        /*
        int rt=0;
        int i;
        int offset=0;// offset for sign
        bool neg=false;
        bool hex=false;
        bool oct=false;
        while(str[offset]==' ') {
            offset++;
        }
        if (str[offset]=='+' || str[offset]=='-') {
            if (str[offset]=='-') {
                neg = true;
            }
            offset += 1;
        }
        if (offset) {
            if (str.size()<offset+1) {
                // error
                return (neg)?-rt:rt;
            }
        }
        if (str[0+offset]=='0') {
            if (str.size()>=3+offset) {
                if (str[1+offset]=='x') {
                    hex = true;
                }
            } else if (str.size()>=2+offset) {
                if (str[1+offset]=='x') {
                    // error
                    return (neg)?-rt:rt;
                } else {
                    oct = true;
                }
            }
        }
        int start = offset;
        if (hex) {
            start += 2;
        } else if(oct) {
            start += 1;
        }
        for (i=start;i<str.size();++i) {
            
            if (hex) {
                char c = str[i];
                c = tolower(c);
                if (c>='0' && c<='9') {
                    int n = c-'0';
                    rt = rt*16+n;
                } else if (c>='a' && c<='f') {
                    int n = c-'a'+10;
                    rt = rt*16+n;
                } else {
                    // error 
                    return (neg)?-rt:rt;
                }
            } else if (oct) {
                char c = str[i];
                if (c<'0' || c>'7') {
                    // error
                    return (neg)?-rt:rt;
                }
                int n = c-'0';
                rt = rt*8+n;
            } else {
                char c = str[i];
                if (c<'0' || c>'9') {
                    // error 
                    return (neg)?-rt:rt;
                }
                int n = c-'0';
                if (rt>=INT_MAX/10) {
                    if (rt==INT_MAX/10) {
                        cout << "tata1"<<endl;
                        if (neg) {
                            cout << "tata2"<<endl;
                            if (n<=7) {
                                cout << "tata3"<<endl;
                                rt = rt*10+n;
                                return (neg)?-rt:rt;
                            } else {
                                return (neg)?INT_MIN:INT_MAX;
                            }
                        } else {
                            if (n<=7) {
                                rt = rt*10+n;
                                return (neg)?-rt:rt;
                            } else {
                                return (neg)?INT_MIN:INT_MAX;
                            }
                        }
                    } else {
                        return (neg)?INT_MIN:INT_MAX;
                    }
                }
                rt = rt*10+n;
            }
        }
        return (neg)?-rt:rt;
        */
    }
};

