#include <iostream>
using namespace std;
int toInt(int &i, string s){
    int res = 0 ;
    while (s[i] >= '0' && s[i] <= '9') {
        res = res * 10 + s[i] - '0';
        i++;
    }
    return res ;
}
int main() {
    int n;
    cin >> n ;
    cin.ignore() ;
    for (int i = 0 ; i < n ; i ++) {
        int g[n] = {0};
        string s ;
       getline(cin, s) ;
       for (int j = 0 ; j < s.length(); j ++){
            if (s[j] != ' ') {
                g[toInt(j, s) - 1] = 1 ;
            }
        }

        for (int j = 0; j < n; j ++){
            cout << g[j]<< " " ;
        }
        cout << endl ;
    }
    return 0;
}