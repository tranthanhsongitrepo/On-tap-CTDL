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
bool isLetter(char in){
    return in >= 'a' && in <= 'z' ;
}
void postFix(string in){
    stack<char> s ;
    for (int i = 0 ; i < in.length(); i ++) {
        if (isLetter(in[i]))
            cout << in[i] ;
        else if (in[i] == ')'){
            while (s.top() != '('){
                cout << s.top() ;
                s.pop() ;
            }
            s.pop() ;
        }
        else if (in[i] == '(')
            s.push('(') ;
        else{
            while (!s.empty() && priority(s.top()) >= priority(in[i])){
                cout << s.top() ;
                s.pop() ;
            }
            s.push(in[i]) ;
        }
    }
    while (!s.empty()){
        cout << s.top() ;
        s.pop() ;
    }
    cout << endl ;
}
int main() {
    int t ;
    cin >> t ;
    // cin.ignore() ;
    while (t --){
        string s;
        cin >> s ;
        postFix(s) ;
    }
    return 0;
}