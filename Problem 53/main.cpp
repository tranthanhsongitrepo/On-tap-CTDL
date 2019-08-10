#include <iostream>
#include <vector>
using namespace std ;
int toNum(string s, int &start){
    int t = 0;
    while (s[start] >= '0' && s[start] <= '9'){
        t = t * 10 + s[start] -  '0' ;
        start ++ ;
    }
    return t ;
}
int main() {
    int t ;
    cin >> t ;
    cin.ignore() ;
    while (t --) {
        string s1, s2;
        getline(cin, s1);
        getline(cin, s2);
        vector<int> v(10001, 0);
        for (int i = 0; i < s1.length(); i += 3) {
            int b = toNum(s1, i) ;
            i += 3 ;
            v[toNum(s1, i)] = b;
        }
        for (int i = 0; i < s2.length(); i += 3) {
            int b = toNum(s2, i) ;
            i += 3 ;
            v[ toNum(s2, i)]  += b ;
        }
        bool flag = false ;
        for (int i = 10000; i >= 0; i--) {
            if (v[i]) {
                if (flag)
                    cout << " + " ;
                else{
                    flag = true ;
                }
                cout << v[i] << "*x^" << i;

                }
        }
        cout << endl ;
    }
    return 0;
}