#include <iostream>
#include <stack>
#include <climits>

using namespace std ;
int longestCorrectBracketSeq(string in){
    stack<int> s ;
    int t[in.length()] = {0} ;
    for (int i = 0 ; i < in.length() ; i ++){
        if (in[i] == '(')
            s.push(i) ;
        else{
            if (!s.empty()) {
                t[i] = i - s.top() + 1 ;
                s.pop();
            }
        }
    }
    int max_l = INT_MIN ;
    for (int i = in.length() - 1; i >= 0 ; i --){
        int l = 0, j = i ;
        while (j >= 0 && t[j]){
            l += t[j] ;
            j = j - t[j ] ;
        }
        if (l > max_l)
            max_l = l ;
    }
    return max_l ;
}
int main() {
    int t ;
    cin >> t ;
    while (t --){
        string in ;
        cin >> in ;
        cout << longestCorrectBracketSeq(in) << endl ;
    }
    return 0;
}