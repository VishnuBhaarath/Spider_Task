/*
    IMPLEMENT merge sort
*/
#include<iostream>

using namespace std;


//default comparison function : results in ascending order
template <class T>
bool comp(T a, T b) {
    return (a > b);
}

//merge two array segments
template <class T>
void merge(T* array, int l, int m, int r, bool (*com)(T a, T b) = comp) {
    T* temp = new T[r-l+1];

    int i,j,k;

    for(i = l, j = m+1, k = 0; i <= m && j <= r;k++) {
        if (com(array[i], array[j])){
            temp[k] = array[j++];
        }
        else  {
            temp[k] = array[i++];
        }
    }

    while (i <= m) {
        temp[k++] = array[i++];
    }

    while (j <= r) {
        temp[k++] = array[j++];
    }

    for (i = l, k = 0; i <= r; i++, k++)
        array[i] = temp[k];

    delete temp;
}

//implementation of merge sort
//  com(a,b) -> bool: should return true when a and b are in wrong order
template <class T>
void mergeSort(T* array, int l, int r, bool (*com)(T a, T b) = comp) {
    if(r > l) {
        int m = (l+r)/2;
        mergeSort(array, l, m, com);
        mergeSort(array, m+1, r, com);
        merge(array, l, m, r, com);
    }
}


//sample comparison function : results in descending order
bool comp2(int a, int b) { 
    return (a<b);
}

//sample usage
int main()
{
    int *A, n;
    cout << "Enter number of elements: ";
    cin >> n;

    A = new int[n];

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cout << i << ": ";
        cin >> A[i];
    }

    cout << endl << "Ascending:\t";

    //default com function (ascending)
    mergeSort(A, 0, n-1);
    for (int i = 0; i < n; i++) {
        cout << A[i] << "\t";
    }
    cout << endl << "Descending:\t";

    //custom com function (descending)
    mergeSort(A, 0, n-1, comp2);
    for (int i = 0; i < n; i++) {
        cout << A[i] << "\t";
    }

    cout << endl;

    delete A;
    return 0;
}