#include <iostream>
using namespace std ;
long long int fibo[94] ;
void fillFibo(){
    fibo[0] = 0 ;
    fibo[1] = 1 ;
    fibo[2] = 1 ;
    for (int i = 3;i < 93; i ++)
        fibo[i] = fibo[i - 1] + fibo[i - 2] ;
}
char getCharAtK(int n, long long int k){
    long long int mid = fibo[n - 2] ;
    if (n == 1) return 'A' ;
    if (n == 2) return 'B' ;
    if (k > mid)
        return getCharAtK(n - 1, k - mid) ;
    return getCharAtK(n - 2 , k) ;

}
int main() {
    int t ;
    cin >> t ;
    fillFibo() ;
    while (t --){
        int n;
        long long int k;
        cin >> n >> k ;
        cout << getCharAtK(n, k) << endl ;
    }
    return 0;
}
/*
A
B
AB
BAB
ABBAB
BABABBAB
ABBABBABABBAB
BABABBABABBABBABABBAB*/
