#include <iostream>
#include <climits>

using namespace std ;
void printArray(int a[], int n){
    for (int i = 0; i < n ; i ++)
        cout << a[i] << " " ;
    cout << endl ;
}
void bubbleSort(int *a, int n){
    for (int i = 0 ; i < n - 1 ; i ++){
        bool flag = false ;
        for (int j = 0; j < n - 1 ; j ++) {
            if (a[j] > a[j + 1]){
                flag = true ;
                swap(a[j], a[j + 1]) ;
            }
        }
        if (!flag)
            return ;
        cout << "Buoc " << i + 1 << ": " ;
        printArray(a, n) ;
    }
}
int main() {
    int n;
    cin >> n;
    int a[n] ;
    for (int i = 0 ; i < n ; i ++)
        cin >> a[i] ;
    bubbleSort(a, n) ;
    return 0;
}