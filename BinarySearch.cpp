#include <iostream> 
using namespace std;

int BinarySearch(int nums[], int leftSide, int rightSide, int target) {
   if (rightSide >= leftSide) {
      int mid = ((leftSide + rightSide)/2);
      if (nums[mid] == target){
        return mid ;
      }//end if in middle
      if (nums[mid] > target){
         return BinarySearch(nums, leftSide, mid-1, target);
      }//end if oh the left side
      if (nums[mid] < target){
         return BinarySearch(nums, mid+1, rightSide, target);
      }//end if on the right side
   } // end master If
   return -1;
} // end BinarySearch


int main(void) {
   int nums[] = {-1,0,3,5,9,12};
   int n = sizeof(nums); 
   int target;
   cout << "Enter the target number: ";
   cin >> target;
   int index = BinarySearch (nums, 0, n-1, target);
   if(index == -1){
      cout<< target <<"  is not present in the array";
   }//end if
   else{
      cout<< target <<" is in the array at index "<< index;
   } //end else
   return 0;
}//end main