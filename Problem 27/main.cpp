#include <iostream>
#include <queue>
using namespace std ;
const long long int MOD = 1e9+7 ;
long long int getMinTime(long long int a[], long long int n){
    priority_queue<long long int, vector<long long int>, greater<> > pq ;
    long long int res = 0 ;
    for (long long int i = 0 ; i < n; i ++)
        pq.push(a[i]) ;
    while (pq.size() != 1){
        long long int t1 = pq.top() ;
        pq.pop() ;
        long long int t2 = pq.top() ;
        pq.pop() ;
        long long int s = (t1 + t2) % MOD;
        res = (res + s) % MOD ;
        pq.push(s) ;
    }
    return res ;
}
int main() {
    long long int n ;
    cin >> n ;
    long long int a[n] ;
    for (long long int i = 0; i < n ; i ++)
        cin >> a[i] ;
    cout << getMinTime(a, n) << endl ;
    return 0;
}