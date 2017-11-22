#ifndef LAB_ALG_SORT_H
#define LAB_ALG_SORT_H

typedef int TYPE;
typedef int (*Comparator)(TYPE a,TYPE b);
// behavior: if a goes before b, return negative value.
//           if a == b, cmp(a,b) and cmp(b,a) both return negative value.

void insertion_sort(TYPE* arr,int size,Comparator cmp);
void bubble_sort(TYPE* arr,int size,Comparator cmp);
/*void merge_sort(TYPE* arr,int size,Comparator cmp);   //Failed  */
/*void quick_sort(TYPE* arr,int size,Comparator cmp); */  //Failed
void merge(int *arr, int low, int mid, int high);
void quickSort(int* arr,int startPos, int endPos);
void merge_sort(int *arr,int first,int last);

#endif