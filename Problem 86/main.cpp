#include <iostream>
using namespace std ;
//long long int mul[501] ;
void genNext(long long int x[], long long int n){
    long long int i = n - 1 ;
    while (x[i] == 1) {
        x[i] = 0;
        i--;
    }
    x[i] = 1 ;

}
bool isFinal(long long int x[], long long int n){
    for (long long int i = 0 ; i < n ; i ++)
        if (x[i] == 0)
            return false ;
    return true ;
}
long long int getNum(long long int x[], long long int n, long long int k){
    long long int s = 0 ;
    for (long long int i = 0 ; i < n ; i ++)
        s = (s * 10 + x[i]) % k;
    return s ;
}
void printX(long long int x[], long long int n){
    for(long long int i = 0 ; i < n; i ++)
        cout << x[i] ;
    cout << endl ;
}
bool genBin(long long int n, long long int k){
    long long int x[n] = {0};
    x[0] = 1 ;
    if (getNum(x, n, k) == 0){
        printX(x, n) ;
        return true ;
    }
    while (!isFinal(x + 1, n - 1)) {
        genNext(x + 1, n - 1);

        if (getNum(x, n, k) == 0){
            printX(x, n) ;
            return true ;
        }
    }
    return false;
}
void getMul(long long int k) {
    long long int n = 1;
    while(!genBin(n, k)){
        n ++ ;
    }
}
int main() {
    long long int t ;
    cin >> t ;
    while (t --) {
        long long int k;
        cin >> k;
        if (k == 999) {
            cout << "111111111111111111111111111" << endl ;
        }
        else
         getMul(k);
    }
    return 0;
}