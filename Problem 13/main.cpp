#include <iostream>
#include <algorithm>
using namespace std ;
struct Input{
    string s ;
    bool map[26] = {0};
    void fillMap() {
        for (int i = 0; i < s.length(); i ++){
            map[s[i] -  'A'] = true ;
        }
    }


};
int getNoOfLoop(Input a[], int permutations[], int n){
    int c = 0 ;
    for (int i = 1; i < n; i ++){
        for (int j = 0 ; j < a[permutations[i]].s.length(); j ++){
            if (a[permutations[i - 1]].map[a[permutations[i]].s[j] - 'A']){
                c ++ ;
            }
        }
    }
    return c ;
}
int getMin(Input a[], int n){
    int permutations[n] ;
    for (int i = 0; i < n ; i ++)
        permutations[i] = i ;
    int min_loop = getNoOfLoop(a, permutations, n) ;
    while (next_permutation(permutations, permutations + n)){
        int loop = getNoOfLoop(a, permutations, n) ;
        if (min_loop > loop)
            min_loop = loop ;
    }
    return min_loop ;
}
int main() {
    int n ;
    cin >> n ;
    Input a[n] ;
    for (int i = 0; i < n ; i ++){
        string s ;
        cin >> s ;
        Input temp;
        temp.s = s ;
        temp.fillMap() ;
        a[i] = temp ;
    }
    cout << getMin(a, n) ;
    return 0;
}