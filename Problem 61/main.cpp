#include <iostream>
#include <stack>
#include <climits>

using namespace std ;
int correctBracketSeq(string in){
    stack<char> s ;
    int c = 0 ;
    for (int i = 0 ; i < in.length() ; i ++){
        if (in[i] == '(')
            s.push(in[i]) ;
        else{
            if (!s.empty() && s.top() != ')') {
                s.pop();
            }
            else
                s.push(in[i]) ;
        }
    }
    while (!s.empty()){
        if (s.top() != ')')
            c ++ ;
        s.pop() ;
        if (s.top() != '(')
            c ++ ;
        s.pop() ;
    }
    return c ;

}
int main() {
    int t ;
    cin >> t ;
    while (t --){
        string in ;
        cin >> in ;
        cout << correctBracketSeq(in) << endl ;
    }
    return 0;
}