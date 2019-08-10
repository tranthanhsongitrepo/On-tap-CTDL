#include <iostream>
#include <stack>
using namespace std ;
void printBracketOrder (string ex) {
    stack<int> s ;
    int order = 1 ;
    int a[ex.length()] = {0};
    for  (int i = 0 ; i < ex.length(); i ++) {
        if (ex[i] == '(') {
            s.push(i) ;
            a[i] = order ++ ;
        }
        else if (ex[i] == ')'){
            a[i] = a[s.top()] ;
            s.pop() ;
        }
    }
    for (int i = 0 ; i < ex.length() ; i ++)
        if (a[i] != 0)
            cout << a[i] << " " ;
        cout << endl ;
}
int main() {
    int t ;
    cin >> t ;
    while (t --){
        string ex ;
        cin >> ex ;
        printBracketOrder(ex) ;
    }
    return 0;
}