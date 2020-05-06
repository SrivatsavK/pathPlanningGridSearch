#include <iostream>
#include <vector.h>

/* This program outputs minimum number of steps required for a robot to reach goal position from start position
 * SimpleSearch method is implemented by opening the nodes with minimum g value (path with minimum number of open nodes) */

using namespace std;

int simpleSearch(int &arr,int start,int goal){
	i = 0; // initializing x index of the node
	j = 0; // initializing y index of the node
	g = 0; // g value at the current node
	vector <int> closedNodes [arr.size()/arr[0].size()][arr[0].size()]{0} // initializing this as boolean 0 - open; 1- closed
	vector <int> openNodes [1][3]{g,start}; // adding g value to the indexes
	vector <int> node{start};
	while(node != goal){
		closedNodes[i][j] = 1;
		openNodes.pop_back();
		
		// opening nodes
		g++;
		if (arr[i+1][j] != 1 && closedNodes[i+1][j] != 1 && i+1 < arr.size()/arr[0].size(){
			openNodes.push_back({g,i+1,j})
		}
		if (arr[i-1][j] != 1 && closedNodes[i-1][j] != 1 && i-1 > 0){
			openNodes.push_back({g,i-1,j})
		}
		if (arr[i][j+1] != 1 && closedNodes[i][j+1] != 1 && j+1 < arr.size()-1{
			openNodes.push_back({g,i,j+1})
		}
		if (arr[i][j-1] != 1 && closedNodes[i][j-1] != 1 && j-1 > 0){
			openNodes.push_back({g,i,j-1})
		}
		
	}
	
}


int main()
{
	// Defining the discrete grid for the search plan
	int arr [5][6] {{0,0,1,0,0,0},
					{0,0,1,0,0,0},
					{0,0,0,0,1,0},
					{0,0,1,1,1,0},
					{0,0,0,0,1,0}};
	
	int start [1][2] {{0,0}};
	int goal [1][2] {{4,5}};
					
	return 0;
}
