#include <iostream>
#include <vector>
#include <algorithm>

/* This program outputs minimum number of steps required for a robot to reach goal position from start position
 * SimpleSearch method is implemented by opening the nodes with minimum g value (path with minimum number of open nodes) */

std::vector <int> simpleSearch(std::vector < std::vector<int> > &arr,std::vector <int> &start,std::vector <int> &goal,std::vector < std::vector<int> > &delta){
	/* This function returns the number of steps and goal position
	 * Inputs:
	 * 	arr -> grid for which search algorithm needs to be run
	 * 	start -> start position for the agent
	 * 	goal -> goal position for the agent
	 * 	delta -> the actions that agent can take
	 * 
	 * Outputs:
	 * 	result -> a vector containing the number of steps and goal position
	 * */

	int x{0}; // initializing x index of the node
	int y{0}; // initializing y index of the node
	int g{0}; // g value at the current node
	
	int x2{0}; // initializing x index for expanded nodes
	int y2{0}; // initializing y index for expanded nodes
	int g2{0}; // initializing g value for expanded nodes
	
	// initializing a vector with open nodes
	std::vector <std::vector <int> > openNode{{g,start[0],start[1]}} ;
	
	// making a copy of the array for storing closedNodes
	std::vector <std::vector<int> > closedNodes (arr);
	
	bool resign{false}; // if unable to find the path
	bool found{false}; // if found the path
	
	
	// expanding the nodes and finding the path
	while(found == false && resign == false){
		
		// popping the node with lowest g value
		std::sort(openNode.begin(),openNode.end());
		std::reverse(openNode.begin(),openNode.end());
		g = openNode[openNode.size()-1][0]; // g value of the node to be popped
		x = openNode[openNode.size()-1][1]; // x index of the node to be popped
		y = openNode[openNode.size()-1][2]; // y index of the node to be popped
		closedNodes[x][y] = 1; // adding the node to the closedNodes, bool "1" => closed nodes
		openNode.pop_back(); 
		
		// expanding nodes
		size_t len_actions{delta.size()};
		g2 = g + 1;
		for (size_t i{0}; i < len_actions ; i++){
			x2 = x + delta[i][0];
			y2 = y + delta[i][1];
			
			// Checking if found the goal else checking if its a valid node to be opened
			if (x2 == goal[0] && y2 == goal[1]){
				found = true;
			return {g2,x2,y2};
			} else if (x2 >= 0 && x2 < arr.size() && y2 >= 0 && y2 < arr[0].size() && closedNodes[x2][y2] != 1){
				openNode.push_back({g2,x2,y2});
				closedNodes[x2][y2] = 1; 
			}
		}
		
		// checking for the resign condition => no more nodes to open
		if (openNode.size() == 0){
			resign = true;
			return {-1,-1,-1};
		}
	}
}

int main()
{
	/* The function that runs the main script */
	
	// Defining the discrete grid for the search plan
	std::vector< std::vector<int> > arr {{0,0,1,0,0,0},
										{0,0,1,0,0,0},
										{0,0,0,0,1,0},
										{0,0,1,1,1,0},
										{0,0,0,0,1,0}};

	// Initializing actions for the agent
	std::vector <std::vector <int> > delta {{-1,0}, // up
											{1,0}, // down
											{0,1}, // right
											{0,-1}};// left

	std::vector<int> start {0,0}; // start position
	std::vector<int> goal {4,5}; // goal position
	
	std::vector <int> result(3); // initializing vector to store results
	
	result = simpleSearch(arr,start,goal,delta);
	
	// printing if the path was found or not
	if (result[0] == -1){
		std::cout << "no path found" << std::endl;
	} else {
		std::cout << "Path found" << std::endl;
		std::cout << "Minimum number of steps: " << result[0] << std::endl;
		std::cout << "Goal Co-ordinates reached: [ " << result[1] << " , " << result[2] << " ]" << std::endl; 
	}
	
	return 0;
}
