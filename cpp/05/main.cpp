#include <bits/stdc++.h>
using namespace std;

int len_arr;

long long int merge(vector<int> &arr, int inicio, int meio, int fim) {
    int i = inicio;
    int j = meio;
    int k = 0;
    long long int inv = 0;
    vector<int> ordenado(fim-inicio);

    while (i < meio && j < fim) {
        if (arr[i] <= arr[j]) {
            ordenado[k++] = arr[i++];
        }
        else {
            ordenado[k++] = arr[j++];
            inv += (meio-i);
        }
    }

    while (i < meio) 
        ordenado[k++] = arr[i++];
    
    while (j < fim) 
        ordenado[k++] = arr[j++];

    for (int m = inicio; m < fim; m++) 
        arr[m] = ordenado[m-inicio];
    
    ordenado.clear();
    return inv;
}

long long int merge_sort(vector<int> &arr, int inicio, int fim) {
    long long int inv = 0;

    if (inicio < fim-1) {
        int meio = (fim + inicio) / 2;

        inv += merge_sort(arr, inicio, meio);
        inv += merge_sort(arr, meio, fim);
        inv += merge(arr, inicio, meio, fim);
    }

    return inv;
}

long long int solve(vector<int> arr) {
    return merge_sort(arr, 0, len_arr);
}

int main() {
    vector<int> arr(100000);
    
    cin >> len_arr;
    for (int i = 0; i < len_arr; i++) 
        cin >> arr[i];

    cout << solve(arr) << endl;

    return 0;
}