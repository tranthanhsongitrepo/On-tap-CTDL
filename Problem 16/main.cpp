#include <iostream>
using namespace std ;
long long int pow2[51] ;
long long int getNumAtKBT(long long int n, long long int k){
    long long int mid = pow2[n - 1] ;
    if (k == mid)
        return n ;
    if (k > mid){
       return getNumAtKBT(n - 1, k - mid) ;
    }
    return getNumAtKBT(n - 1, k) ;

}
void fillPow2(){
    pow2[0] = 1 ;
    for (long long int i = 1; i <=50; i ++){
        pow2[i] = pow2[i - 1] * 2 ;
    }
}
long long int getNumAtK(long long int n, long long int k){
    return getNumAtKBT (n, k) ;
}
int main() {
    fillPow2() ;
    long long int t ;
    cin >> t ;
    while (t --){
        long long int n, k ;
        cin >> n >> k;
        cout << getNumAtKBT(n, k) << endl ;
    }
    return 0;
}
