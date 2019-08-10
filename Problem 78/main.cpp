#include <iostream>
#include <queue>
#include <cstring>

using namespace std ;
bool isPrime[10000] ;
int pow10[5] = {1, 10, 100, 1000};
void sieve() {
    memset(isPrime, 1, sizeof( isPrime)) ;
    for  (int i = 2 ; i * i <= 10000; i ++){
        if (isPrime[i]) {
            for (int j = i * i; j < 10000; j += i) {
                isPrime[j] = false;
            }
        }
    }
}
int noOfSteps (int st, int end) {
    queue<int> q ;
    q.push(st) ;
    bool visited[9000] = {0};
    int prev_size = 1, c = 0 ;
    visited[st - 1000] = true ;
    while (q.front() != end) {
        int temp = q.front() ;
        for (int i = 3 ; i >= 0; i --){
            int t = q.front() - temp % 10 * pow10[3 - i] ;
            for (int j = 0 + i == 0; j <= 9; j ++){
                int p = t + j * pow10[3 - i] ;
                if (!visited[p - 1000] && isPrime[p]) {
                    q.push(p);
                    visited[p - 1000] = true ;
                }
            }
            temp /=  10 ;
        }
        prev_size -- ;
        q.pop() ;
        if (prev_size == 0) {
            prev_size = q.size() ;
            c ++ ;
        }
    }
    return c ;
}
int main() {
    sieve();
    int t ;
    cin >> t ;
    while (t --){
        int st, end ;
        cin >> st >> end ;
        cout << noOfSteps(st, end) << endl ;
    }
    return 0;
}