#include <iostream>

using namespace std ;
bool haveSubSumS(int a[], int n, int s) {
    bool t[n][s + 1] = {0};
    t[0][a[0]] = true ;
    for (int i = 1; i < n; i ++){
        t[i][a[i]] = true ;
        for (int j = 1 ; j <= s; j ++) {
            if (j != a[i]) {
                if (j < a[i])
                    t[i][j] = t[i - 1][j];
                else
                    t[i][j] = t[i - 1][j - a[i]] || t[i - 1][j];
            }
        }
    }
    return t[n - 1][s] ;

}
int main() {
    int n, s ;
    cin >> n  >> s ;
    int a[n] ;
    for (int i = 0; i < n ; i ++)
        cin >> a[i] ;
    haveSubSumS(a, n, s) ? cout << "YES" : cout << "NO" ;
    return 0;
}