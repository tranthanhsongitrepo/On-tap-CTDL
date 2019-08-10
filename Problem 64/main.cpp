#include <iostream>
#include <stack>
using namespace std ;
void firstLargerRightNum (int a[], int n){
    stack<int> s ;
    int res[n] ;
    for (int i = 0 ; i < n; i ++) {
        while (!s.empty() && a[s.top()] < a[i]){
            res[s.top()] = a[i] ;
            s.pop() ;
        }
        s.push(i) ;
    }
    while (!s.empty()){
        res[s.top()] = -1 ;
        s.pop() ;
    }
    for (int i = 0 ; i < n ; i ++)
        cout << res[i] << " " ;
    cout << endl ;
}
int main() {
    int t ;
    cin >> t ;
    while (t --){
        int n ;
        cin >> n ;
        int a[n] ;
        for (int i = 0 ; i < n ; i ++)
            cin >> a[i] ;
        firstLargerRightNum(a, n);
    }
    return 0;
}