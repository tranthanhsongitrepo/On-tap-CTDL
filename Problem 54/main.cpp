#include <iostream>
using namespace std ;
int getFirstElim(int n , int m){
    int mod = m % n ;
    return (mod == 0) ? n : mod ;
}
int main() {
    int t ;
    cin >> t ;
    while (t --){
        int n, m ;
        cin >> n >> m ;
        m ++ ;
        int t[n + 1] ;
        t[0] = 0 ;
        t[1] = 0 ;
        t[2] = (getFirstElim(2, m) == 1) ? 2 : 1 ;
        for (int i = 3; i <= n; i  ++){
            int firstElim = getFirstElim(i, m), temp = t[i - 1] + firstElim;
            t[i] = temp <= i ? temp : temp - i ;
        }
        cout << t[n] << endl ;
    }

}