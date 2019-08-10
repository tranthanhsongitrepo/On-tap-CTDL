#include <iostream>
#include <stack>
using namespace std ;
bool isSameType(char a, char b) {
    return (a == '(' && b == ')'
        || a == '[' && b == ']'
        || a == '{' && b == '}') ;
}
bool isOpenning(char a){
    return a == '(' || a == '[' || a == '{' ;
}
bool isCorrectBracketSeq(string in){
    stack<char> s ;
    for (int i = 0 ; i < in.length() ; i ++){
        if (isOpenning(in[i]))
            s.push(in[i]) ;
        else{
            if (!s.empty() && isSameType(s.top(), in[i])) {
                s.pop();
            }
            else
                return false ;
        }
    }return true ;
}
int main() {
    int t ;
    cin >> t ;
    while (t --){
        string s ;
        cin >> s ;
        (isCorrectBracketSeq(s)) ? cout << "YES" << endl : cout << "NO" << endl ;
    }
    return 0;
}