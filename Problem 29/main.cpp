#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std ;

struct Pair{
    int t ;
    int pos ;
    Pair (int t, int pos){
        this->t = t ;
        this->pos = pos ;
    }
    Pair () {
        this->t = 0 ;
        this->pos = -1 ;
    }
    bool operator < (Pair b) {
        return this->t <= b.t ;
    }
};
Pair a[500000] ;
void remove(string& s, int k) {
    int  start = 0, end = s.length() - 1 ;
    for (int i = 0; i <= end; i ++){
        a[i].t = (s[i] - '0') * 10 - i - 1;
        a[i].pos = i ;
    }
    sort(a, a + end + 1) ;
    int i = 0;
    while (k){
        s[a[i++].pos] = '/' ;
        k -- ;
    }
}
int main() {
    int n, k ;
    cin >> n >> k ;
    string s ;
    cin >> s ;
    remove(s, k) ;
    for (int i = 0 ; i < s.length(); i ++)
        if (s[i] != '/')
            cout << s[i] ;
    return 0;
}