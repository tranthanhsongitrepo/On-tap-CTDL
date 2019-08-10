#include <iostream>
#include <vector>
#include <stack>

using namespace std ;
void printArray(int n, int r[]){
    for (int i = 0; i < n ; i ++)
        (r[i] == 0) ? cout << "A" : cout << "B" ;
    cout << endl ;
}
void genNext(int n, int k ,int r[]){
    int i = n - 1;
    while (r[i] == 1)
        r[i--] = 0;
    r[i] = 1 ;
}
bool check(int n, int k, int r[]){
    int count = 0 ;
    for (int i = 0; i <= n - k; i ++) {
        int c = 0 ;
        for (int j = i ; j < k + i; j ++) {
            if (r[j] == 0)
                c++;
        }
        if (c == k)
            count++;
        if (count > 1)
            return false;
    }
        return count == 1 ;
}
bool isFinal(int n, int r[]){
    for (int i = 0 ; i < n; i ++)
        if (r[i] != 1)
            return false ;
        return true ;
}
void genBinary(int n, int k){
    int r[n] = {0};
    if (check(n, k, r))
        printArray(n, r) ;
    vector<string> v ;
    while (!isFinal(n, r)){
        genNext(n, k, r) ;
        if (check(n, k, r)){
            string s ;
            for (int i = 0; i < n; i ++)
                s += r[i] == 0 ? 'A' : 'B' ;
            v.push_back(s) ;
        }
    }
    cout << v.size() << endl ;
    for (int i = 0; i < v.size(); i ++)
        cout << v[i] << endl ;
}
int main() {
    int n, k;
    cin >> n >> k ;
    genBinary(n, k) ;
    return 0;
}