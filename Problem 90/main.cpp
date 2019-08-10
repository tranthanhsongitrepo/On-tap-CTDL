#include <iostream>
#include <algorithm>
#include <vector>

using namespace std ;
struct Edge{
    int v1, v2;
    Edge (int v1, int v2){
        this->v1 = v1 ;
        this->v2 = v2 ;
    }
    bool operator < (Edge b){
        if (this->v1 != b.v1)
            return this->v1 < b.v1;
        return this->v2 < b.v2 ;

    }
};
int toInt(int &i, string s){
    int res = 0 ;
    while (s[i] >= '0' && s[i] <= '9') {
        res = res * 10 + s[i] - '0';
        i++;
    }
    return res ;
}
int main() {
    int n ;
    cin >> n ;
    vector<Edge> g ;
    cin.ignore() ;
    for (int i = 0; i < n ; i ++){
        string s ;
        getline(cin, s) ;
        for (int j = 0 ; j < s.length(); j ++){
            if (s[j] != ' ') {
                int t = toInt(j, s);
                if (t > i + 1) {
                    Edge temp(i + 1, t);
                    g.push_back(temp);
                }
            }
        }
    }

    sort(g.begin(), g.end()) ;
    for (int i = 0 ; i < g.size(); i ++)
        cout << g[i].v1 << " " << g[i].v2 << endl ;
    return 0;
}