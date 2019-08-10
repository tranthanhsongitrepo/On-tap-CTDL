#include <iostream>
#include <stack>
using namespace std ;

bool isOperator(char c){
    return c == '+' || c == '-' || c == '*' || c == '/' ;
}
string infixFromPrefix(string post){
    stack<string> s ;
    for (int i = 0 ; i < post.length() ; i ++){
        if (isOperator(post[i])){
            string o1 = s.top() ;
            s.pop() ;
            string o2 = s.top() ;
            s.pop() ;
            s.push('(' + o2 + post[i] + o1 + ')') ;
        }
        else{
            string t = "" ;
            t += post[i] ;
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