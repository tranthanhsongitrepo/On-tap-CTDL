#include <iostream>
#include <stack>
using namespace std ;

bool isOperator(char c){
    return c == '+' || c == '-' || c == '*' || c == '/' ;
}
string infixFromPrefix(string pre){
    stack<string> s ;
    for (int i = pre.length() - 1 ; i >= 0 ; i --){
        if (isOperator(pre[i])){
            string o1 = s.top() ;
            s.pop() ;
            string o2 = s.top() ;
            s.pop() ;
            s.push(o1 + o2 + pre[i]) ;
        }
        else{
            string t = "" ;
            t += pre[i] ;
            s.push(t) ;
        }
    }
    return s.top() ;
}
int main() {
    int t ;
    cin >> t ;
    while (t --) {
        string pre ;
        cin >> pre ;
        cout << infixFromPrefix(pre) << endl ;
    }
    return 0;
}