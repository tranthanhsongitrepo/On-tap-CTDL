#include <iostream>
using namespace std ;
int longestPalindromeSubSequene(string s){
    int l =  s.length(), t[l][l] = {0}, max_l = 1 ;
    for (int i = 0 ; i < l; i ++)
        t[i][i] = 1 ;
    for (int r = 2; r <= l; r++){
        for(int i = 0; i < l - r + 1; i ++ ) {
            int j = i + r - 1 ;
            if(s[i] == s[j])
                t[i][j] = t[i + 1][j - 1] + 2 ;
            else
                t[i][j] = max(t[i][j - 1], t[i + 1][j]) ;
            if (t[i][j] > max_l)
                max_l = t[i][j] ;
        }
    }

    return max_l ;
}
int main() {
    int t;
    cin >> t ;
    while (t --){
        string s ;
        cin >> s ;
        cout << longestPalindromeSubSequene(s) << endl ;
    }
    return 0;
}