#include <iostream>
using namespace std ;
long long int* merge(long long int a[], long long int b[], long long int n, long long int m){
    long long int i = 0, j = 0, c = 0 ;
    long long int* res = new long long int[n + m] ;
    while (i != n && j != m){
        if (a[i] < b[j])
            res[c] = a[i ++] ;
        else
            res[c] = b[j++] ;
        c ++ ;
    }
    while (i != n){
        res[c ++] = a[i ++] ;
    }
    while (j != m){
         res[c ++] = b[j ++] ;
    }
    return res ;
}
long long int* mergeSortUtil(long long int a[], long long int l, long long int h){
    if (l <= h) {
        if (h - l == 0) {
            long long int *temp = new long long int[1];
            temp[0] = a[l];
            return temp;
        }
        long long int mid = (h + l) / 2;

        long long int *left = mergeSortUtil(a, l, mid);
        long long int *right = mergeSortUtil(a, mid + 1, h);
        return merge(left, right, mid - l + 1, h - mid);
    }
    return NULL ;
}
long long int* mergeSort(long long int a[], long long int n){
    return mergeSortUtil(a, 0, n - 1) ;
}
int main() {
    long long int n ;
    cin >> n ;
    long long int a[n] ;
    for (long long int i = 0; i < n; i  ++){
        cin >> a[i] ;
    }
    long long int* sorted_a = mergeSort(a, n) ;
    for (long long int i = 0 ; i < n ; i ++)
        cout << sorted_a[i] << " " ;
    return 0;
}