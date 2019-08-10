#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;

bool check(int n, int k, int x[], int a[10][10]){
    int s = 0 ;
    for (int i = 0 ; i < n ; i ++){
       s += a[i][x[i]] ;
    }
    return s == k ;
}
void get(int x[], int k, int n, int a[10][10]){
    vector<string> v ;
    while (next_permutation(x, x + n)){
        if (check(n, k, x, a)){
            string s ;
            for (int i = 0; i < n; i ++) {
                s += (char) x[i] + '0';
            }
            v.push_back(s) ;

        }
    }
    cout << v.size() << endl ;
    for (int i = 0 ; i < v.size(); i ++){
        for (int j = 0 ; j < n ; j ++)
            cout << v[i][j] - '0' + 1 << " " ;
        cout << endl ;
    }
}
void solve (int n, int k, int a[10][10]){
    int x[n] ;
    for (int i = 0 ; i < n ; i ++)
        x[i] = i ;
    get(x, k, n, a) ;
}
int main() {
    int n, k ;
    cin >> n >> k ;
    int a[10][10] ;
    for (int i = 0 ; i < n ; i ++)
        for (int j = 0 ; j < n ; j ++)
            cin >> a[i][j] ;
    solve(n, k, a) ;
    return 0;
}