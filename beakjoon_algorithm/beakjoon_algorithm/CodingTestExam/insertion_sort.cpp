////
////  insertion_sort.cpp
////  beakjoon_algorithm
////
////  Created by kgh on 03/03/2019.
////  Copyright © 2019 kgh. All rights reserved.
////
//
//#include <stdio.h>
//#include <iostream>
//using namespace std;
//
//void insertion_sort(int arr[],int size){
//    int i,j;
//    int key;
//
//    for(i=1; i<size; i++){
//        key = arr[i];
//        for(j=i-1; j>=0; j--){
//
//            if(arr[j] > key){
//                arr[j+1] = arr[j];
//                //공간을 하나 더 생성해버린다. 동일한값 arr[j] , arr[j+1]
//                //그 사이에 값을 넣어버리고 이제 key값을 arr[j+1]에 키값을 넣어준다.
//            }else{
//                break;
//            }
//        }
//        arr[j+1] = key;
//    }
//
//}
//int main(void){
//    int arr[5] = {2,4,6,1,3};
//    int size = sizeof(arr) / sizeof(int);
//
//    insertion_sort(arr,size);
//
//    for(int i=0; i<size; i++){
//
//
//        cout << arr[i];
//    }
//
//
//
//
//}


#include <stdio.h>
#include <iostream>
using namespace std;
int main(void){
    int temp;
    int arr[5] = {4,6,1,2,5};
    int size = sizeof(arr) / sizeof(int);
    
    
    for(int i=0; i<size-1; i++){
        int j = i;
        while(arr[j] > arr[j+1]){
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
            // 계속해서 진행하면서 값 여부를 확인하기 위해서
            j--;
        }
    }
    
    for(int i=0; i < size; i++){
        cout << arr[i];
    }
}
