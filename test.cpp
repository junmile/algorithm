#include <stdio.h>

int number = 10;
int data[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};

void quickSort(int *data, int start, int end){
    if(start>=end){
        return;
    }
    
    int key = start;
    int left = key+1;
    int right = end;
    int temp;

    while(left<=right){//엇갈릴때까지 반복
        while(data[left]<=data[key]){// 키값보다 큰값을 만날때 까지
            left++;
        }
        while(data[right]>=data[key] && right > start){// 키값보다 작은값을 만날때 까지
            right--;
        }
        if( left > right){ // 엇갈렸다면
            temp = data[right];
            data[right] = data[key];
            data[key] = temp;
        }else{
            temp = data[left];
            data[left] = data[right];
            data[right] = temp;
        }
        quickSort(data, start, right - 1);
        quickSort(data, right + 1, end);

        

    }


}

int main(void){
    quickSort(data, 0, number - 1);
    for(int i = 0; i < number; i++){
        printf("%d", data[i]);
    }
}