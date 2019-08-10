#include <iostream>
#include <climits>

using namespace std ;
int longestCommonSubStringLength(string a, string b){
    int c = 0, t[a.length()][b.length()] = {0}, max_l = 0 ;
    for (int i = 0 ; i < b.length(); i ++)
        t[0][i] = a[0] == b[i] ;
    for (int i = 1; i < a.length(); i ++){
        for (int j = 0; j < b.length(); j ++){
            if (a[i] == b[j]){
                t[i][j] = t[i - 1][j - 1] + 1 ;
            }
            else
                t[i][j] = max(t[i - 1][j], t[i][j - 1]) ;
            if (i == a.length() - 1 && t[i][j] > max_l)
                max_l = t[i][j] ;
        }
    }
    return max_l ;
}
int main() {
    string a, b ;
    cin >> a >> b ;
    cout << longestCommonSubStringLength(a, b) ;
    return 0;
}