#include <stdio.h>
#include "sort_function.h"
#include<stdlib.h>
/*
typedef int TYPE;
typedef int (*Comparator)(TYPE a,TYPE b);
// behavior: if a goes before b, return negative value.
//           if a == b, cmp(a,b) and cmp(b,a) both return negative value.

void insertion_sort(TYPE* arr,int size,Comparator cmp);
void bubble_sort(TYPE* arr,int size,Comparator cmp);
void merge_sort(TYPE* arr,int size,Comparator cmp);
void quick_sort(TYPE* arr,int size,Comparator cmp);
*/
int sort(int , int );
int sort(int a,int b){
    if(a>=b)return -1;
    else return 1;
}
void insertion_sort(TYPE* arr,int size,Comparator cmp){
    int i,j;
    cmp=&sort;
    for(i=1;i<=size;i++){
        for(j=i;j>0;j--){
            if(cmp(arr[j],arr[j-1])>0){
                int index = arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=index;
            }
        }
    }
    /*for(i=0;i<=size-1;i++){
        printf("%d ",arr[i]);
    }  */
}
void bubble_sort(TYPE* arr,int size,Comparator cmp){
    int i,j;
    for( i=size-1;i>0;i--){
        for(j=0;j<i;j++){
            if(cmp(arr[j],arr[j+1])<0){
                int index=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=index;
            }
        }
    }
    /*for(i=1;i<=size;i++){
        printf("%d ",arr[i-1]);
    }  */
}
/*void merge_sort(TYPE* arr,int size,Comparator cmp){                   //i dont know how to use cmp there
    int first=0;
    int last=size-1;
    int mid=(first+last)/2;
    int count=mid+1;
    merge_sort(arr,mid,cmp);
    merge_sort(arr+count,last-mid,cmp);
    merge(arr,first,mid,last);
}
void merge(int *arr, int low, int mid, int high){
    int i, k;
    int *tmp = (int *)malloc((high-low+1)*sizeof(int));
    int left_low = low;
    int left_high = mid;
    int right_low = mid + 1;
    int right_high = high;
    for(k=0; left_low<=left_high && right_low<=right_high; k++){
        if(arr[left_low]<=arr[right_low]){
            tmp[k] = arr[left_low++];
        }else{
            tmp[k] = arr[right_low++];
        }
    }
    if(left_low <= left_high){
        for(i=left_low;i<=left_high;i++)
            tmp[k++] = arr[i];
    }
    if(right_low <= right_high){
        for(i=right_low; i<=right_high; i++)
            tmp[k++] = arr[i];
    }
    for(i=0; i<high-low+1; i++)
        arr[low+i] = tmp[i];
    free(tmp);
}
/*void quick_sort(TYPE* arr,int size,Comparator cmp){
    int i=0,j=0;
    int base=0;
    for(i;i<size;i++){
        if(cmp(arr[i],arr[base])>0)j++;
    }
    int *save_small=(int *)malloc(j*sizeof(int));
    int *save_huge=(int *)malloc((size-j)*sizeof(int));
    for(i=0;i<size;i++){
        if(cmp(arr[i],arr[base])>0){
            *save_small=arr[i];
            save_small++;
        }
        else{
            *save_huge=arr[i];
            save_huge++;
        }
    }
    for(i=0;i<size;i++){
        if(arr[0]==save_small[0]){                                       //judge the place where the arr start

        }
    }
}  */
void merge_sort(int *arr,int first,int last){
    int mid = 0;
    if(first<last){
        mid = (first+last)/2;
        merge_sort(arr, first, mid);
        merge_sort(arr, mid+1,last);
        merge(arr,first,mid,last);
    }
}
void merge(int *arr, int low, int mid, int high){
    int i, k;
    int *tmp = (int *)malloc((high-low+1)*sizeof(int));
    int left_low = low;
    int left_high = mid;
    int right_low = mid + 1;
    int right_high = high;
    for(k=0; left_low<=left_high && right_low<=right_high; k++){
        if(arr[left_low]<=arr[right_low]){
            tmp[k] = arr[left_low++];
        }else{
            tmp[k] = arr[right_low++];
        }
    }
    if(left_low <= left_high){
        for(i=left_low;i<=left_high;i++)
            tmp[k++] = arr[i];
    }
    if(right_low <= right_high){
        for(i=right_low; i<=right_high; i++)
            tmp[k++] = arr[i];
    }
    for(i=0; i<high-low+1; i++)
        arr[low+i] = tmp[i];
    free(tmp);
}
void quickSort(int* arr,int startPos, int endPos)
{
    int i, j;
    int key;
    key = arr[startPos];
    i = startPos;
    j = endPos;
    while (i<j)
    {
        while (arr[j] >= key && i<j)--j;
        arr[i] = arr[j];
        while (arr[i] <= key && i<j)++i;
        arr[j] = arr[i];
    }
    arr[i] = key;
    if (i - 1>startPos) quickSort(arr, startPos, i - 1);
    if (endPos>i + 1) quickSort(arr, i + 1, endPos);
}
int main(){
    int arr[5]={4,7,1,3,0};
    Comparator cmp;
    cmp=sort;
    insertion_sort(arr,5,cmp);
    for(int i=0;i<=4;i++){
        printf("%d ",arr[i]);
    }putchar('\n');
    bubble_sort(arr,5,cmp);
    for(int i=0;i<=4;i++){
        printf("%d ",arr[i]);
    }printf("\n");
    merge_sort(arr,0,4);
    for(int i=0;i<=4;i++){
        printf("%d ",arr[i]);
    }printf("\n");
    quickSort(arr,0,4);
    for(int i=0;i<=4;i++){
        printf("%d ",arr[i]);
    }printf("\n");
    return 0;
}
