#include <iostream>
#include <climits>

using namespace std ;
void printArray(int a[], int n){
    for (int i = 0; i < n ; i ++)
        cout << a[i] << " " ;
    cout << endl ;
}
void swapSort(int a[], int n){
    for (int i = 0 ; i < n - 1 ; i ++){
        for (int j = i + 1; j < n ; j ++){
            if (a[j] < a[i])
                swap(a[i], a[j]) ;
        }
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
    swapSort(a, n) ;
    return 0;
}