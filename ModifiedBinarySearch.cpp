//modified binary search 

#include <iostream>

int pivot(int arr[],int end){ 
    int leftSide=0;
    int rightSide=end-1;
    
    while(leftSide<=rightSide){
        
        int mid=(leftSide+rightSide)/2;

        //base
        if(leftSide >=rightSide)
            return -1;
        //mid-1 should be greater than or equal to left side
        if(mid>leftSide && arr[mid]<arr[mid-1])
            return mid-1;

        //mid + 1 should be less than or equal to right side
        if(mid<rightSide&&arr[mid]>arr[mid+1])
            return mid;

        if (arr[leftSide] >= arr[mid]) {
            rightSide=mid-1;
        }//end if leftside >= mid

        else{
            leftSide=mid+1;
        }//end else
  
  
  
    }//end while
  
}//end pivot

int modified_binary_search(int arr[],int target,int startIndex, int endIndex){

    int mid=((startIndex+endIndex)/2);

    //base case
    if(endIndex<startIndex)
        return -1;

    
    //if middle element is the target
    if (arr[mid] == target) 
        return mid;
    
    //if need to search in the left half of the array
    else if(arr[mid]>target){
        return modified_binary_search(arr,target,startIndex,mid-1);
    }//end if left half

    //if need to search in the right half of the array
    else {
        return modified_binary_search(arr,target,mid+1,endIndex);
    }//end else right half
  
}//end modified binary search




int main() {

   int arr[] = {24,25,36,70,0,9,11,20};
   int arrLength = sizeof(arr)/sizeof(arr[0]);
   int target = 24;

   int ans = -1;
     
  
   int pivotVal=pivot(arr,arrLength);
   //no pivot
   if(pivotVal == -1)
        ans=modified_binary_search(arr,target,0,arrLength-1);

    //pivot is target
   else if(arr[pivotVal]==target)
        ans=pivotVal;
    //pivot right of target
   else if(arr[0]<=target){
        ans =modified_binary_search(arr, target, 0, pivotVal-1);
   }//end else if

   //right side of pivot
   else 
        ans=modified_binary_search(arr,target,pivotVal+1,arrLength-1);


   std::cout<<ans;
   
   return 0;
}//end main