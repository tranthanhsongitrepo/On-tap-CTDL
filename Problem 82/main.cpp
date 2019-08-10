#include <iostream>
#include <queue>
using namespace std ;
long long int noOfBND(long long int n) {
    long long int c = 1 ;
    queue<long long int> q ;
    q.push(1);
    while (!q.empty()){
        long long int t = q.front() * 10 ;
        q.pop();
        if (t > 0) {
            if (t <= n) {
                q.push(t);
                c ++ ;
            }
            if (t + 1 <= n) {
                q.push(t + 1);
                c ++ ;
            }
        }
    }
    return c ;
}
int main() {
    int t ;
    cin >> t ;
    while (t --) {
        long long int n ;
        cin >>  n ;
        cout << noOfBND(n) << endl ;
    }
    return 0;
}