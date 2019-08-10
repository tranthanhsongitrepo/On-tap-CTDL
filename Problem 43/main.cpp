#include <iostream>
#include <climits>
#include <vector>

using namespace std ;
void printArray(vector<int> a, int n){
    for (int i = 0; i < a.size() ; i ++)
        cout << a[i] << " " ;
    cout << endl ;
}
void swapSort(int a[], int n){
    vector<int> v ;
    for (int i = 0 ; i < n; i ++){
        int j = 0 ;
        while (j < v.size() && a[i] >= v[j]) j ++ ;
        v.insert(v.begin() + j, a[i]) ;
        cout << "Buoc " << i << ": " ;
        printArray(v, n) ;
    }
}
int main() {
    int n;
    cin >> n;
    int a[n] ;
    for (int i = 0 ; i < n ; i ++)
        cin >> a[i] ;
    swapSort(a, n) ;
    return 0;
}