// Name: Lawrence Menegus
// Date: 11/18/23
// Course: Data Structures and Algorithms
// Description: This program creates a a Adjacency Matrix and list for a undirected and unweighted Graph 

#include <iostream>
#include <vector>

using namespace std;

struct Edge
{
	int vertex1;
	int vertex2;
};

// Phototypes 
void initializeMatrix(int adjMat[4][4]); 
void insertEdge(Edge e, int adjMat[4][4]); 
void printGraph(int adjMat[4][4]); 
void printAdjacencyList(int adjMat[4][4]); 



int main()
{
	int graph[4][4];
	initializeMatrix(graph);


	// Creates edges to the graph 
	Edge e1 = { 1, 2 };
	Edge e2 = { 1, 4 };
	Edge e3 = { 2, 1 };
	Edge e4 = { 2, 3 };
	Edge e5 = { 3, 2 };
	Edge e6 = { 4, 1 };


	// Inserts the Edges to the graph 
	insertEdge(e1, graph);
	insertEdge(e2, graph);
	insertEdge(e3, graph);
	insertEdge(e4, graph);
	insertEdge(e5, graph);
	insertEdge(e6, graph);

	

	cout << "Adjacency Matrix:" << endl;
	cout << endl;
	printGraph(graph);
	

	cout << "\nAdjacency list " << endl; 
	cout << endl;
	printAdjacencyList(graph); 


	return 0;
}



// Initialize the matrix to zero
void initializeMatrix(int adjMat[4][4])
{
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			adjMat[i][j] = 0;
}

// Add an edge between two vertices
void insertEdge(Edge e, int adjMat[4][4])
{
	// Prints if the vertex 1 and 2 are the same 
	if (e.vertex1 == e.vertex2)
	{
		cout << "Same vertex " << e.vertex1 << " and " << e.vertex2 << endl;
		return;
	}
	adjMat[e.vertex1 - 1][e.vertex2 - 1] = 1;
	adjMat[e.vertex2 - 1][e.vertex1 - 1] = 1;
}

// Print the adjacency matrix
void printGraph(int adjMat[4][4])
{

	for (int i = 1; i <= 4; i++)
	{
		if (i == 1) {
			cout << "    " << i;
		}
		else
		{
			cout << "   " << i;
		}
	}
	cout << endl;



	// Creates Matrix 
	for (int i = 0; i < 4; ++i)
	{
		cout << i + 1 << " ";

		for (int j = 0; j < 4; ++j)
			cout << " [" << adjMat[i][j] << "]";
		cout << endl;
	}
}

// Print the adjacency list
void printAdjacencyList(int adjMat[4][4])
{
	// Creates a vector for the vertices
	vector<vector<int>> adjList(4);
	
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (adjMat[i][j] == 1)
				adjList[i].push_back(j + 1);
		}
	}


	// Prints out order pairs for the Verticies and edges 
	for (int i = 0; i < 4; ++i)
	{
		for (int neighbor : adjList[i])
			cout << "<" << i + 1 << "," << neighbor << "> "; 
	}
	cout << endl; 
}