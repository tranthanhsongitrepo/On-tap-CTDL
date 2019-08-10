#include <iostream>
using namespace std ;
bool isSubString(string s, string p){
     // KMP search
     int pre[p.length()] = {0} ;
     int i = 1, j = 0 ;
     while (i < p.length()){
         if (p[i] == p[j]) {
             j ++ ;
             pre[i++] = j ;
         }
         else{
             if (j != 0)
                j = pre[j - 1] ;
             else
                 i ++ ;
         }
     }
     i = 0 ;
     j = 0 ;
     while (i < s.length()){
         if(s[i] == p[j]) {
             i ++ ;
             j ++ ;
             if (j == p.length())
                 return true ;
         }
         else {
             if (j != 0)
                 j = pre[j - 1] ;
             else
                 i ++ ;
         }
     }
     return false ;
};
int main() {
    int t;
    cin >> t ;
    while (t --) {
        string s, p ;
        cin >> s >> p ;
        isSubString(s, p) ? cout << "YES" << endl : cout << "NO" << endl ;
    }
    return 0;
}
// AABA