#include <iostream>
#include <math.h>
using namespace std;
#define  MAX 100
void printList(int *arr,int numberOf);
void inputList(int *arr,int n);
void selectSortASC(int *arr,int n);
void swap(int &a,int &b);
void selectSortASCII(int *arr,int n);
void selectSortRecuse(int *arr,int n,int i);
void insertSortDES(int *arr,int n);
void insertSortIIDES(int *arr,int n,int i);
void bubbleSortASC(int *arr,int n);
void merge(int arr[], int l, int m, int r);
void mergeSort(int *arr, int l, int r);
void mergerSort(int *arr,int n);
int main(){
  int *arr = new int [MAX],numberOf;
   int a[MAX]={1,3,2,7,6,2,5,9,8};
   mergerSort(a,9);
    printList(a,9);
}
/*a) Input a list of n numbers, the print the list.*/
void inputList(int *arr,int numberOf){
    int i;
    for(int i=0;i<numberOf;i++){
     cin>>arr[i];
    }
}
void printList(int *arr,int numberOf){
    int i;
    for(i=0;i<numberOf;i++){
        cout<<arr[i];
    }
    cout<<endl;
}
void swap(int *a,int *b){
    int temp=*a;
        *a=*b;
        *b=temp;
}
void swapRecuse(int *arr,int i,int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
//b)Sorting the list by ascending order using Selection algorithm, then print the sorted list.
void selectSortASC(int *arr,int n){
    int i,j,minIndex;
    for(i=0;i<n;i++){
        minIndex=i;
            for(j=i+1;j<n;j++){
                if(arr[minIndex]>arr[j]){
                    minIndex=j;
                }
                swap(&arr[minIndex],&arr[i]);
            }
    }
}
void selectSortRecuse(int *arr,int n,int i){
    int min=i;
    for(int j=i+1;j<n;j++){
        if(arr[j]<arr[min]){
            min=j;
        }
    }
    swapRecuse(arr,i,min);
    if(i+1<n){
        selectSortRecuse(arr,n,i+1);
    }
}
/*c) Sorting the list by descending order using Insert algorithm, then print the sorted list.*/
void insertSort(int *arr,int n){//1
   int j,key;
   for(int i=0;i<n;i++){
       key=arr[i];
       j=i-1;
       while (arr[j]<key&&j>=0){
           arr[j+1]=arr[j];
           j--;
       }
       arr[j+1]=key;
   }
}
void insertSortIIDES(int *arr,int n,int i){//2
    int j=i-1,key;
    key=arr[i];
    while (arr[j]<key&&j>=0){
             arr[j+1]=arr[j];
             j--;
    }
       arr[j+1]=key;
         if(i+1<n){
             insertSortIIDES(arr,n,i+1);
         } else{
             return;
         }
}
/*d) Sorting the list by ascending order using Bubble algorithm, then print the sorted list.*/
void bubbleSortASC(int *arr,int n){
    bool  checkSwap= false;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i]<arr[j]){
                swap(&arr[i],&arr[j]);
                    checkSwap=true;
            }
        }
        if(checkSwap== false){
            break;
        }
    }
}
/*e) Sorting the list by descending order using Merger algorithm, then print the sorted list.*/
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
void merge(int arr[], int l, int m, int r)
{
    int k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[100], R[100];

    for(int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(int j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    int i = 0;
    int j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] > R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergerSort(int *arr,int n){
    for(int i=1;i<n;i=i*2){
        for(int j=0;j<n-1;j+=2*i){
            int middle= min(i+j-1,n-1);
            int right=min(j+2*i-1,n-1);
            merge(arr,j,middle,right);
        }
    }
}