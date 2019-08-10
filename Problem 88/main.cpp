#include <iostream>
#include <queue>
#include <cmath>
using namespace std ;
/*int a[10000000] = {0} ;*/
long long int noOfSteps(long long int n){
    queue<long long int> q ;

    q.push(n);
    long long int c = 0, prev_size = 1 ;
    while (q.front() != 1){
        double sqrtn = sqrt(n) ;
        for (long long int i = 1; i <= sqrtn; i ++ ){
            if (q.front() % i == 0){
                long long int p = q.front() / i ;
                q.push(max(p, i)) ;
            }
        }
        q.push(q.front() - 1) ;
        q.pop() ;
        prev_size -- ;
        if (prev_size == 0) {
            prev_size = q.size() ;
            c ++ ;
        }
    }
    return c ;
}
int main() {
    long long int t ;
    cin >> t;
    while (t --){
        long long int n ;
        cin >> n ;
        cout << noOfSteps(n) << endl ;
    }
    return 0;
}