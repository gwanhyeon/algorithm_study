#include <stdio.h>
#include <iostream>
using namespace std;
int sorted[10001];
int arr[10001];
void merge(int *arr,int m,int middle,int n){
    
    int i = m;
    int j = middle + 1;
    int k = m;
    
    while(i <= middle && j <= n){
        if(arr[i] <= arr[j]){
            sorted[k] = arr[i];
            i++;
            
        }else{
            sorted[k] = arr[j];
            j++;
        }
        k++;
    }
    if(i > middle){
        for(int t=j; t<=n; t++){
            sorted[k] = arr[t];
            k++;
        }
        
    }else{
        for(int t=i; t<=middle; t++){
            sorted[k] = arr[t];
            k++;
        }
    }
    for(int t=m; t<=n; t++){
        arr[t] = sorted[t];
    }
    
    
    
    
}
void mergesort(int *arr,int m,int n){
    if(m<n){
        
        int middle = (m+n)/ 2;
        mergesort(arr,m,middle);
        mergesort(arr,middle+1,n);
        merge(arr,m,middle,n);
    }
}

void quickSort(int* data, int start, int end) {
    if (start >= end) { // 원소가 1개인 경우 그대로 두기
        return;
    }
    
    int key = start; // 키는 첫 번째 원소
    int i = start + 1, j = end, temp;
    
    while(i <= j) { // 엇갈릴 때까지 반복
        while(i <= end && data[i] <= data[key]) { // 키 값보다 큰 값을 만날 때까지
            i++;
        }
        while(j > start && data[j] >= data[key]) { // 키 값보다 작은 값을 만날 때까지
            j--;
        }
        if(i > j) { // 현재 엇갈린 상태면 키 값과 교체
            temp = data[j];
            data[j] = data[key];
            data[key] = temp;
        } else { // 엇갈리지 않았다면 i와 j를 교체
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    }
    
    quickSort(data, start, j - 1);
    quickSort(data, j + 1, end);
}

int main(void) {
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
//    quickSort(data, 0, n - 1);
    mergesort(arr,0,n-1);
    reverse(arr,arr+n);
    for(int i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }
    return 0;
}
