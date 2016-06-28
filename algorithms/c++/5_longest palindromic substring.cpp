class Solution {
public:
    string longestPalindrome(string s) {
        int i,j;
        
        int n=s.size();
        if (n<=1) {
            return s;
        }
        int oddr=0, om=0, er=0,em=0;
        for (i=0;i<n;++i) {
            int mor = (i<(n-1-i))?i:(n-1-i);
            int mer = ((i+1)<(n-1-i))?(i+1):(n-1-i);
            for (j=1;j<mer+1;++j) {
                int l = s[i+1-j];
                int r = s[i+j];
                if (l==r) {
                    if(j>er) {
                        er = j;
                        em = i;
                    }
                } else {
                    break;
                }
            }
            for (j=1;j<mor+1;++j) {
                int l=s[i-j];
                int r=s[i+j];
                if (l==r) {
                    if (j>oddr) {
                        oddr = j;
                        om = i;
                    }
                }else{
                    break;
                }
            }
        }
        if (2*er>2*oddr+1) {
            return s.substr(em-er+1, 2*er);
        } else {
            return s.substr(om-oddr, 2*oddr+1);
        }
    /*
    const char *str=s.c_str();
    int n = s.size(); // get length of input string

    // table[i][j] will be false if substring str[i..j]
    // is not palindrome.
    // Else table[i][j] will be true
    bool *table;
    table = new bool[n*n];
    memset(table, 0, n*n);
 
    // All substrings of length 1 are palindromes
    int maxLength = 1;
    for (int i = 0; i < n; ++i)
        table[i*n+i] = true;
 
    // check for sub-string of length 2.
    int start = 0;
    for (int i = 0; i < n-1; ++i)
    {
        if (str[i] == str[i+1])
        {
            table[i*n+i+1] = true;
            start = i;
            maxLength = 2;
        }
    }
 
    // Check for lengths greater than 2. k is length
    // of substring
    for (int k = 3; k <= n; ++k)
    {
        // Fix the starting index
        for (int i = 0; i < n-k+1 ; ++i)
        {
            // Get the ending index of substring from
            // starting index i and length k
            int j = i + k - 1;
 
            // checking for sub-string from ith index to
            // jth index iff str[i+1] to str[j-1] is a
            // palindrome
            if (table[(i+1)*n+j-1] && str[i] == str[j])
            {
                table[i*n+j] = true;
 
                if (k > maxLength)
                {
                    start = i;
                    maxLength = k;
                }
            }
        }
    }
    free(table);
    return s.substr(start, maxLength); // return length of LPS
    */
    }
};
