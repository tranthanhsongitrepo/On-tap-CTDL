#include <stdio.h>
#include <vector>
using namespace std ;
int largestCowCap(int a[], int c, int n){
    vector<vector<bool> > t (n + 1,vector<bool>(c + 1, 0));

	for (int i = 0 ; i < n + 1; i ++)
		t[i][0] = true ;
    for (int i = 1; i <= n ; i   ++){
         for (int j = c; j >= 0 ; j --) {
            if (j < a[i - 1]) {
                if (t[i - 1][j] == 1)
                    t[i][j] = 1;
            }
            else
            	t[i][j] = t[i - 1][j] || t[i - 1][j - a[i - 1]] ;

            if (i == n && t[i][j] == 1)
                return j ;
        }
    }
}
int main() {
    int c, n ;
    scanf("%d%d", &c, &n) ;
    int a[n] ;
    for (int i = 0 ; i < n; i ++)
        scanf("%d", &a[i]) ;
    printf("%d", largestCowCap(a, c, n));
    return 0;
}