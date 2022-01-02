#include <stdio.h>
#include <limits.h>

#define N 5

//seperate method to print the path
void printPath(int shortestPathFinderArray[], int j){
	
	//recusrion gang
	if (shortestPathFinderArray[j] == - 1){
		return;
	}//end base case
	printPath(shortestPathFinderArray, shortestPathFinderArray[j]);
	printf("%d ", j);
}//end printPath

//print
int printSolution(int distance[], int n, int shortestPathFinderArray[], int cityTwo, int cityOne){
	
	for (int i = 1; i < N; i++){
		if (cityTwo == i){
					printf("The shortest path distance has cost: %d \nThe path is as follows: %d ", distance[i], cityOne);
		printPath(shortestPathFinderArray, i);
		}//end if

	}//end for
}//end print

int minimumVertexDistance(int distance[],	bool setOfVertexes[]){
	
	// Initialize min value
	int extreme = INT_MAX;
	int indexOfMin;

	for (int i = 0; i < N; i++){
		if (setOfVertexes[i] == false && distance[i] <= extreme){
			extreme = distance[i], indexOfMin = i;
		}//end if
	}//end for

	return indexOfMin;
}//end minimumVertexDistance


void algorithmSolution(int path[N][N], int cityOne, int cityTwo){
	

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


			if (!setOfVertexes[j] && path[minimum][j] && (distance[minimum] + path[minimum][j] < distance[j])){
				shortestPathFinderArray[j] = minimum;
				distance[j] = distance[minimum] + path[minimum][j];
			}//end if
		}//end for j
	}//end for i

	printSolution(distance, N, shortestPathFinderArray, cityTwo, cityOne);
}//end algorithm

int main(){

	int path[N][N] = { 
					{0, 0, 1, 0, 0},
					{0, 0, 0, 4, 0},
					{0, 3, 0, 12, 4},
					{0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0}
					};
	int cityOne = 0;
	int cityTwo = 3;
	algorithmSolution(path, cityOne, cityTwo);
	return 0;
}//end main
