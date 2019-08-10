#include <iostream>
#include <stack>
using namespace std;
int priority(char c){
    switch (c) {
        case '+' : case '-' :
            return 1 ;
        case '*' : case '/' :
            return  2 ;
        case '^' :
            return 3 ;
        case '(' :
            return -1 ;
    }
}
bool isOperator (char c) {
    return c == '+' || c == '-' || c == '/' || c == '*' ;
}
bool hasRedundantBracket(string in){
    stack<char> s ;
    for (int i = 0 ; i < in.length(); i ++) {
        if (in[i] == ')'){
            if (s.top() == '(')
                return true ;
            while (s.top() != '('){
                s.pop() ;
            }
            s.pop() ;
        }
        else if (in[i] == '(')
            s.push('(') ;
        else if (isOperator(in[i])){
            while (!s.empty() && priority(s.top()) >= priority(in[i])){
               s.pop() ;
            }
            s.push(in[i]) ;
        }
    }
    return false ;
}
int main() {
    int t ;
    cin >> t ;
    cin.ignore() ;
    while (t --){
        string s;
        getline(cin, s) ;
        hasRedundantBracket(s) ? cout << "Yes" << endl : cout << "No" << endl ;
    }
    return 0;
}