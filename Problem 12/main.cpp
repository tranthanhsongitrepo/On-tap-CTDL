#include <iostream>
#include <climits>

using namespace std ;
int a[15][15], min_cost = INT_MAX ;
int a_min = INT_MAX ;
int getLowerBOund(int cities_left, int cur_cost){
    return cities_left * a_min + cur_cost ;
}
void getMinTravelCostBT(int c, int i, int n, int cur_cost, bool visited[]){
    if (getLowerBOund(n - c, cur_cost) > min_cost)
        return ;
    if (c == n - 1){
        if (cur_cost + a[0][i] < min_cost)
            min_cost = cur_cost + a[0][i] ;
        return ;
    }
    visited[i] = true ;
    for (int j = 0 ; j < n; j ++){
        if (!visited[j]){
            getMinTravelCostBT(c + 1, j, n, cur_cost + a[i][j], visited) ;
        }
    }
    visited[i] = false ;
}
int main() {
   int n ;
   cin >> n ;
   for (int i = 0 ; i < n ; i ++) {
       for (int j = 0; j < n; j++) {
           cin >> a[i][j];
           if (a_min > a[i][j] && a[i][j] != 0)
               a_min = a[i][j] ;
       }
   }
   bool visited[n] = {0};
   getMinTravelCostBT(0, 0, n, 0, visited) ;
   cout << min_cost ;
    return 0;
}