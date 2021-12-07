#include<stdio.h>
//make swapping easier using pointers and a method
void swap(int* a, int* b){
	int t = *a;
	*a = *b;
	*b = t;
}//end swap

int partition (int arr[], int low, int high){
    //pivot
	int pivotVal = arr[high];
    //get index of small
	int i = (low - 1); 
    //Print the newly partitioned array
    printf("Partitioned: ");
	printf( "{");
	for(int j=0;j< 8;j++){
        if (j != (8-1) ){
        printf("%d",arr[j]);// print array
        printf(", ");
        }//end if
        else {
            printf("%d",arr[j]); 
        }//end else
    }//end for
    printf("}");
    printf("\n");


    //partition
	for (int j = low; j <= high- 1; j++){
		
		if (arr[j] <= pivotVal){
			i++; //increment smaller element
			swap(&arr[i], &arr[j]);
		}//end if
	}//end for
    //swap
	swap(&arr[i + 1], &arr[high]);

    //print swapped array
	printf("Swapped: ");
	printf( "{");
	for(int j=0;j< 8;j++){
        if (j != (8-1) ){
        printf("%d",arr[j]);// print array
        printf(", ");
        }//end if
        else {
            printf("%d",arr[j]); 
        }//end else
    }//end for
    printf("}");
    printf("\n");
	printf("\n");
    //iterate
	return (i + 1);

}//end partition

void quickSort(int arr[], int low, int high){
	
	if (low < high){
	
		int split = partition(arr, low, high);
	
		quickSort(arr, low, split - 1);
		quickSort(arr, split + 1, high);
		
	}//end if
}//end quicksort

int main(){

    //setup array
	int arr[] = {49, 38, 65, 97, 76, 13, 27, 49};
	int n = sizeof(arr)/sizeof(arr[0]);

    //print original array
	printf("Original Array: \n");
	printf( "{");
	for(int i=0;i< n;i++){
        if (i != (n-1) ){
        printf("%d",arr[i]);// print array
        printf(", ");
        }//end if
        else {
            printf("%d",arr[i]); 
        }//end else
    }//end for
    printf("}");
    printf("\n");
	printf("\n");

    //quicksort
	quickSort(arr, 0, n-1);

    //print sorted array
	printf("Sorted array: \n");
	printf( "{");
	for(int j=0;j< n;j++){
        if (j != (n-1) ){
        printf("%d",arr[j]);// print array
        printf(", ");
        }//end if
        else {
            printf("%d",arr[j]); 
        }//end else
    }//end for
    printf("}");
    printf("\n");
	
    return 0;

}//end main
