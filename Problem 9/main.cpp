#include <iostream>
using namespace std ;
//long long int mul[501] ;
void genNext(int x[], int n){
    int i = n - 1 ;
    while (x[i] == 9) {
        x[i] = 0;
        i--;
    }
   x[i] = 9 ;

}
bool isFinal(int x[], int n){
    for (int i = 0 ; i < n ; i ++)
        if (x[i] == 0)
            return false ;
        return true ;
}
long long getNum(int x[], int n){
    long long int s = 0 ;
    for (int i = 0 ; i < n ; i ++)
        s = s * 10 + x[i] ;
    return s ;
}
long long int genBin(int n, int k){
    int x[n] = {0};
    x[0] = 9 ;
    long long int temp = getNum(x, n) ;
    if (temp % k == 0)
        return temp ;
    while (!isFinal(x + 1, n - 1)) {
        genNext(x + 1, n - 1);
        long long int t = getNum(x, n) ;
        if (t % k == 0)
            return t ;
    }
    return -1 ;
}
long long getMul(int k) {
    int n = 1;
    long long int temp = genBin(n, k) ;
    while(temp == -1){
        n ++ ;
        temp = genBin(n, k) ;
    }
    return temp ;
}
int main() {
    int t ;
    cin >> t ;
    while (t --){
        int k ;
        cin >> k ;
        cout << getMul(k) << endl ;
    }
    return 0;
}