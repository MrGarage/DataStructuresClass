
#include <bits/stdc++.h>
using namespace std;
//number of vertices
#define N 3

//find vertex with smallest vertexNum
int minimumVertex(int vertexNum[], bool setOfNs[]){
	
	int min = INT_MAX, min_index;

	for (int v = 0; v < N; v++)
		if (setOfNs[v] == false && vertexNum[v] < min)
			min = vertexNum[v], min_index = v;

	return min_index;
}//end minimumVertex

//print
void printMST(int constructedMST[], int city[N][N]){
	int totalCountWeight = 0;

	for (int i = 1; i < N; i++){
		totalCountWeight = totalCountWeight + city[i][constructedMST[i]];
	}//end for

	 cout << "The Minimum Cost is " << totalCountWeight;

}//end print

//find the mst
void mstSolver(int city[N][N]){
	
	int constructedMST[N];
	int vertexNum[N];
	bool setOfNs[N];
	//vertexes as infinite
	for (int i = 0; i < N; i++){
		vertexNum[i] = INT_MAX;
		setOfNs[i] = false;
	}//end for

	//first vertex hard code, first node is root
	vertexNum[0] = 0;
	constructedMST[0] = -1; 

	//make sure correct number of vertices
	for (int j = 0; j < N - 1; j++)	{

		int smallestVertex = minimumVertex(vertexNum, setOfNs);
		//add it to the set
		setOfNs[smallestVertex] = true;

		//update values
		for (int k = 0; k < N; k++)

			//update values only if the city is smaller than vertexNum
			if (city[smallestVertex][k] && setOfNs[k] == false && city[smallestVertex][k] < vertexNum[k]){
				constructedMST[k] = smallestVertex;
				vertexNum[k] = city[smallestVertex][k];
			}//end if
	}//end for

	// print the constructed MST
	printMST(constructedMST, city);
}//end mstSolver

//main
int main(){
	
	int city[N][N] = { { 0, 5, 6 }, 
						{ 5, 0, 1, }, 
						{ 6, 1, 0, } };

	
	mstSolver(city);

	return 0;
}//end main


