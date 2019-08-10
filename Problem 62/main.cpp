#include <iostream>
#include <algorithm>
#include <set>
#include <stack>
#include <vector>

using namespace std ;
struct Pair {
    int i, j ;
};
bool isFinal(int n, int k, int a[]){
    for (int i = 0 ; i < k; i ++)
        if (a[i] != n - k + i + 1)
            return false ;
    return true ;
}
void bracketSeq(string in, vector<Pair>& v) {
    stack<int> s;
    for (int i = 0; i < in.length(); i++) {
        if (in[i] == '(')
            s.push(i);
        else if (in[i] == ')') {
            Pair p;
            p.i = s.top();
            p.j = i;
            v.push_back(p) ;
            s.pop();
        }
    }
}

void genNext(int n, int k, int a[]){
    int i = k - 1 ;
    while (a[i] == n - k + i + 1) i -- ;
    a[i++] ++ ;
    for (i; i < k; i ++){
        a[i] = a[i - 1] + 1 ;
    }
}

void deleteBrackets(string s){
    set<string> p_set ;
    vector<Pair> v ;
    bracketSeq(s, v) ;
    for (int i = 1 ; i <= v.size() ; i ++) {
        int a[i] ;
        int t1[s.length()] = {0} ;
        for (int j = 0 ; j < i; j ++)
            a[j] = j ;
        for (int k = 0; k < i; k ++)
            t1[v[a[k]].i] = 1, t1[v[a[k]].j] = 1 ;
        string temp1 ;
        for (int k =0 ; k < s.length(); k ++) {
            if (t1[k] == 0)
                temp1 += s[k];
        }
        p_set.insert(temp1) ;
        while (!isFinal(v.size() - 1, i, a)){
            genNext(v.size() - 1, i, a) ;
            int t[s.length()] = {0} ;
            string temp ;
            for (int k = 0; k < i; k ++)
                t[v[a[k]].i] = 1, t[v[a[k]].j] = 1 ;
            for (int k =0 ; k < s.length(); k ++) {
                if (t[k] == 0)
                    temp += s[k];
            }
            p_set.insert(temp) ;
        }
    }
    set<string>::iterator it ;
    for (it = p_set.begin(); it != p_set.end(); it ++)
        cout << *it << endl ;

}
int main() {
    string s ;
    cin >> s ;
    deleteBrackets(s) ;
    return 0 ;
}