#include <stdio.h>

int number, data[1000001];


void quickSort(int *data, int start, int end){
    if(start>=end){
        return;
    }

    int key = start;
    int left = start + 1, right=end, temp;
    while(left <= right){
        while(data[left]<=data[key]){
            left++;
        }
        while(right>start && data[right]>=data[key]){
            right--;
        }
        if(left>right){
            temp = data[right];
            data[right] = data[key];
            data[key] = temp; 
        }else{
            temp = data[right];
            data[right] = data[left];
            data[left] = temp;
        }
    }
    quickSort(data, start, right-1);
    quickSort(data, right + 1, end);
}

int main(void){
    scanf("%d", &number);
    for(int i = 0; i<number; i++){
        scanf("%d", &data[i]);
    }
    quickSort(data, 0, number-1);
    for(int i = 0; i<number; i++){
        printf("%d ", data[i]);
    }
}