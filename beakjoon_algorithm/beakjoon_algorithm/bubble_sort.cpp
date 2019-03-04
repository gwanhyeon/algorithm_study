//버블 정렬


#include <stdio.h>
#include <iostream>
using namespace std;

void bubble_sort(int arr[],int num){
    int temp;
    for(int i=0; i<num; i++){
        // 마지막은 비교하지 않기때문에 -1을 빼준다.
        for(int j=0; j<num-i-1; j++){
            // 오름차순 정렬이므로 arr[j]가 클경우 작은값과 바꿔주게된다.
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
    
}
int main(void){
    int num;
    int arr[5] = {5,4,3,2,1};
    num = sizeof(arr) / sizeof(int);
    bubble_sort(arr,num);
    for(int i=0; i<num; i++){
        cout << arr[i];
    }
    
    
}
