#include <iostream>

using namespace std;

int  partition(int arr[] , int si, int ei);
void quickSort(int arr[] , int si , int ei);

int main() {

    int arr[]={39,23,41,12,98,31,90,21};


    quickSort(arr,0,7);
    //cout<<partition(arr,0,7)<<endl;

    for(int i=0 ; i<8 ; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}


void quickSort(int arr[] , int si , int ei){

    if(si<ei){
        int c=0;
        c=partition(arr,si,ei);
        quickSort(arr,si,c-1);
        quickSort(arr,c+1,ei);

    }else{
        return;
    }

}


int  partition(int arr[] , int si, int ei){

    int count=0;
    int x=arr[si];
    for(int i=si; i<(ei-si)+1 ; i++){
        if(arr[i]<x){
            count++;
        }
    }
    swap(arr[si+count],arr[si]);
    int i=si;
    int j=ei;

    while(i<(si+count) && j>(si+count)){
        if(arr[i]>arr[si+count] && arr[j]<arr[si+count]){
            swap(arr[i++],arr[j--]);
        }
        else if(arr[i]<arr[si+count] && arr[j]>arr[si+count]){
            i++;
            j--;
        }
        else if(arr[i]<arr[si+count] && arr[j]<arr[si+count]){
            i++;
        }
        else if(arr[i]>arr[si+count] && arr[j]>arr[si+count]){
            j--;
        }
        else{
            i++;
            j--;
        }

    }

    return si+count;

}

void swap(int &a, int &b){
    int temp;
    temp=a;
    a=b;
    b=temp;
}
