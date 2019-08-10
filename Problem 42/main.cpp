#include <iostream>
#include <climits>

using namespace std ;
void printArray(int a[], int n){
    for (int i = 0; i < n ; i ++)
        cout << a[i] << " " ;
    cout << endl ;
}
void insertionSort(int *a, int n){
    for (int i = 0 ; i < n - 1 ; i ++){
        int min_pos = i ;
        for (int j = i + 1; j < n ; j ++){
            if (a[j] < a[min_pos])
                min_pos = j ;
        }
        swap(a[i], a[min_pos]) ;
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
    insertionSort(a, n) ;
    return 0;
}