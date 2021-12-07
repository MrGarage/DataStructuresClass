#include<stdio.h>
//plan: go through and whichever one is the same as the one in a couple of values
//is the one that appears 1/4 of the time. 
int findMostCommonInt(int arr[]) {
    //int n = sizeof(arr)/sizeof(arr[0]);
    int search = 8 / 4;// split up to search
    for (int i = 0; i + search < 8; ++i)
      if (arr[i] == arr[i + search]){
           printf("%d", arr[i]);
         return arr[i]; 
      } 
      
    return -1;
    
}//end findMostCommonInt

int main(){
    int arr[] = {1,2,2,6,6,6,7,10};
    printf("The most common value is: ");
    findMostCommonInt(arr);
}//end main