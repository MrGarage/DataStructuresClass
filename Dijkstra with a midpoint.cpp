#include <stdio.h>
#include <limits.h>

#define N 8

//print
int printSolution(int distance[], int n, int shortestPathFinderArray[], int cityTwo, int cityOne){
	int cityMid = 2;
    int combinedCost = 0;
  for (int i = 1; i < N; i++){
 
		if (cityTwo == i){
                 combinedCost = distance[i] + combinedCost;
				//printf(" %d \n %d ", distance[i], combinedCost);
                //printf( " %d ", combinedCost);
		       // printf( " %d" , printPath(shortestPathFinderArray, i));
		}//end if
      //  printPath(shortestPathFinderArray, i);
	}//end for
   // printf(" %d \n", combinedCost);
   return combinedCost;
}//end print

int minimumVertexDistance(int distance[],	bool setOfVertexes[]){
	
	// Initialize min value
	int extreme = INT_MAX;
	int indexOfMin;

	for (int v = 0; v < N; v++){
		if (setOfVertexes[v] == false && distance[v] <= extreme){
			extreme = distance[v], indexOfMin = v;
		}//end if
	}//end for

	return indexOfMin;
}//end minimumVertexDistance


int algorithmSolution(int path[N][N], int cityOne, int cityTwo){
	

	int distance[N];

	//true if the value is in array
	bool setOfVertexes[N];

	int shortestPathFinderArray[N];

	//initialize as 0
	for (int k = 0; k < N; k++)	{
		shortestPathFinderArray[0] = -1;
		distance[k] = INT_MAX;
		setOfVertexes[k] = false;
	}//end for k

	//source is 0 away from itself
	distance[cityOne] = 0;

	//find shortest path for each vertex
	for (int i = 0; i < N - 1; i++)	{

		//minimum distance 
		int minimum = minimumVertexDistance(distance, setOfVertexes);
		//mark vertex as visited
		setOfVertexes[minimum] = true;

		//update distance values if it is less than already is
		for (int j = 0; j < N; j++){
			if ((distance[minimum] + path[minimum][j] < distance[j]) && !setOfVertexes[j] && path[minimum][j] ){
				shortestPathFinderArray[j] = minimum;
				distance[j] = distance[minimum] + path[minimum][j];
			}//end if
		}//end for j
	}//end for i
    int combinedCost;
    
     return printSolution(distance, N, shortestPathFinderArray, cityTwo, cityOne);
}//end algorithm

int main(){
    int combinedCost;
	int path[N][N] = { 
					{0, 2, 0, 0, 0, 0, 0, 0},
					{0, 0, 3, 10, 0, 0, 0, 0},
					{0, 0, 0, 0, 7, 0, 0, 0},
					{0, 0, 4, 0, 5, 0, 0, 0},
					{0, 0, 0, 0, 0, 2, 0, 0},
                    {0, 0, 0, 0, 0, 0, 3, 0},
                    {0, 0, 0, 0, 0, 0, 0, 9},
                    {0, 0, 0, 0, 0, 0, 0, 0}
					};
	int cityOne = 0;
	int cityTwo = 7;
    int cityMid = 3;
	printf("The cost of the first half of the path is: %d \n" , algorithmSolution(path, cityOne, cityMid));
    
   printf ("The cost of the second half of the path is:  %d \n" ,algorithmSolution(path, cityMid, cityTwo));
   combinedCost = algorithmSolution(path, cityOne, cityMid) + algorithmSolution(path, cityMid, cityTwo);
   printf ( "The combined cost of the full path is: %d ", combinedCost);
   

	return 0;
}//end main
