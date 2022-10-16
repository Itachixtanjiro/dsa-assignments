#include <iostream>                   
using namespace std;        
/*
QUESTION:How would you search for an element in an array/list whose size is unknown?
SOLUTION: We can search an element in an array whose size is unknown in O(logn) time complexity provided that the array is in sorted order (here i am taking case of ascending order).We can do this by making some modification in binary search technique.
The concept behind this approach is:
  ->Take inital value of i as 0 and j as 1.
  ->Now increase j to j*2 until arr[j] exceed the key to be searched.
  ->Now search the key using binary search between i and j.
*/

//For Simple Binary Search Function->
int binary_search(int arr[],int i,int j,int key){
    int n=(i+j)/2; //m=middle term
    while(i<=j){   //i=starting index , j=ending index
    if(arr[n]==key){return n;}  // if key to be searched is present we will see the key and it will get returned
    else{
        if(arr[n]<key){i=n+1;}
        else{j=n-1;}
    }
    n=(i+j)/2;
    }
    return -1;  // when element is not present we will return -1 index
}
//For Enhanced binary search function or Binary search for array with unknown lenght
int binary_search_unknown(int arr[],int key){
    //starting i as 0 and j as 1.
    int i=0,j=1;
    //We will increment j until arr[j] exceeds key to be searched.
    while(arr[j]<key){
        i=j;
        j=2*j;
    }
    //Now calling Simple Binary Search between the range of i to j.
    return binary_search(arr,i,j,key);
}
// Priyanshu
// SID-21105060
// ECE 