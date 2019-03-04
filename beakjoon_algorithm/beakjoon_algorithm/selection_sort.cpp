//#include <stdio.h>
//#include <iostream>
//using namespace std;
//void selection_sort(int arr[],int size){
//    int min = 0;
//    int temp = 0;
//
//    for(int i=0; i<size; i++){
//        // 맨처음값을 min으로 넣는다고 생각하면된다
//        min = i;
//        for(int j=i+1; j<size; j++){
//            // 최소값 변경 arr[min]보다 작으므로
//            if(arr[j] < arr[min]){
//                min = j;
//            }
//        }
//        // 정렬코드
//        temp = arr[i];
//        arr[i] = arr[min];
//        arr[min] = temp;
//
//    }
//}
//int main(void){
//
//    int arr[5] = {7,1,2,3,4};
//    int size = sizeof(arr) / sizeof(int);
//    selection_sort(arr,size);
//
//    for(int i=0; i<size; i++){
//        cout << arr[i];
//    }
//
//}
//

// 10 * (10 + 1) / 2 의 시간복잡도가 나온다 다시 말하면 n * ( n + 1 ) / 2

#include <stdio.h>
#include <iostream>
using namespace std;

int main(void){
    int index,min,size;
    int arr[5] = {6,1,4,7,2};
    size = sizeof(arr) / sizeof(int);
    
    
    for(int i=0; i<size; i++){
        // 중요 min값을 처음부터 init 하는것이 아니다.
        min = 99999;
        for(int j=i; j<size; j++){
            // min보다 값이 작을경우 min값을 새로 저장시키고, 현재 j의 인덱스값을 index 변수에 저장한다
            if(min > arr[j]){
                min = arr[j];
                index = j;
            }
        }
        // swap
        int temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }
    for(int i=0; i<size; i++){
        cout << arr[i];
    }

}
