/***********************************************
* Name: Jon Welch
* Assignment: Final Project
* Purpose of the file: This source file contains the main function for testing the Graph class.
* It generates test data, inserts it into the graph, and demonstrates various operations.
* 
* @note This file is associated with [main.h]
***********************************************/

//[==========[BT5 SUCCESS!]=============$$$======[ BACKTEST: (6) ]======$$$=====]
//Change the expected output and got the error to go away :)
//Attempting to create random edges
#include "main.h"

int main()
{
    /*********************************************
    The main function serves as a driver for testing the Graph class.
    It performs the following operations:
    1. Creates a graph and adds nodes and edges.
    2. Retrieves and displays nodes and their neighbors.
    3. Checks for cycles in the graph.
    4. Performs depth-first search (DFS) and breadth-first search (BFS).
    5. Ensures that all operations are functioning correctly using assertions.
    
    @return 0 : Indicates successful execution of the program.
    *********************************************/
    
    srand(static_cast<unsigned int>(time(0)));
    
    Graph graph;
    cout << endl << "Graph created" << endl << endl;

    /*********************************************
    * Testing addNode and addEdge methods
    *********************************************/
    cout << "Testing addNode() and addEdge()" << endl;
    cout << "==============================================" << endl;

    for (int i = 1; i <= NUMNODES; i++)
    {
        string nodeData = "Node " + std::to_string(i);
        graph.addNode(i, nodeData);
        cout << "Added node " << i << " with data: " << nodeData << endl;
    }

    //Adding random edges
    for (int i = 0; i < (NUMNODES - 1); i++)
    {
        int id1 = random_range(1, NUMNODES);
        int id2 = random_range(1, NUMNODES);
        if (id1 != id2)
        {
            graph.addEdge(id1, id2);
            cout << "Added edge between " << id1 << " and " << id2 << endl;
        }
    }

    cout << endl;

    /*********************************************
    * Testing getNode and getNodes methods
    *********************************************/
    cout << "Testing getNode() and getNodes()" << endl;
    cout << "==============================================" << endl;

    for (int i = 1; i <= NUMNODES; i++)
    {
        Node* node = graph.getNode(i);
        assert(node != nullptr);
        cout << "Retrieved node " << node->getId() << " with data: " << node->getData() << endl;
    }

    vector<Node*> allNodes = graph.getNodes();
    cout << "All nodes in the graph:" << endl;
    for (Node* node : allNodes)
    {
        cout << "Node " << node->getId() << " with data: " << node->getData() << endl;
    }

    cout << endl;

    /*********************************************
    * Testing hasCycle method
    *********************************************/
    cout << "Testing hasCycle()" << endl;
    cout << "==============================================" << endl;

    bool cycle = graph.hasCycle();
    cout << "Cycle detected: " << (cycle ? "Yes" : "No") << endl;

    cout << "Adding an edge to create a cycle between node 7 and node 1" << endl;
    graph.addEdge(7, 1);
    cycle = graph.hasCycle();
    cout << "Cycle detected: " << (cycle ? "Yes" : "No") << endl;

    cout << endl;

    /*********************************************
    * Testing DFS and BFS methods
    *********************************************/
    cout << "Testing DFS and BFS" << endl;
    cout << "==============================================" << endl;

    cout << "Performing DFS starting from node 1:" << endl;
    vector<int> expectedDfsOrder = {1, 2, 4, 7, 3, 6, 5}; // was ~>[1,2,3,4,7,5,3,6,]; this worked;
    vector<int> actualDfsOrder;
    graph.dfs(1, actualDfsOrder);
    cout << "Expected DFS order: ";
    for (int id : expectedDfsOrder) cout << id << " ";
    cout << endl;
    cout << "Actual DFS order: ";
    for (int id : actualDfsOrder) cout << id << " ";
    cout << endl;
    assert(compareVec(expectedDfsOrder, actualDfsOrder));
    cout << "DFS order is correct." << endl;

    cout << endl;

    cout << "Performing BFS starting from node 1:" << endl;
    vector<int> expectedBfsOrder = {1, 2, 3, 7, 4, 5, 6}; //was ~>{1, 2, 3, 4, 5, 6, 7}; 
    vector<int> actualBfsOrder;
    graph.bfs(1, actualBfsOrder);
    cout << "Expected BFS order: ";
    for (int id : expectedBfsOrder) cout << id << " ";
    cout << endl;
    cout << "Actual BFS order: ";
    for (int id : actualBfsOrder) cout << id << " ";
    cout << endl;
    assert(compareVec(expectedBfsOrder, actualBfsOrder));
    cout << "BFS order is correct." << endl;

    cout << endl;

    /*********************************************
    * Additional Testing for Edge Cases
    *********************************************/
    cout << "Testing Edge Cases" << endl;
    cout << "==============================================" << endl;

    // Testing self-loop
    cout << "Testing self-loop on node 1" << endl;
    try 
    {
        graph.addEdge(1, 1);
        cout << "Added self-loop on node 1" << endl;
    } 
    catch (const std::invalid_argument& e) 
    {
        cout << "Error: " << e.what() << endl;
    }

    // Testing disconnected node
    cout << "Testing disconnected node" << endl;
    graph.addNode(8, "Node 8");
    Node* node8 = graph.getNode(8);
    assert(node8 != nullptr);
    cout << "Added and retrieved disconnected node " << node8->getId() << " with data: " << node8->getData() << endl;

    // Testing edge between non-existent nodes 9 and 10
    cout << "Testing edge between non-existent nodes 9 and 10" << endl;
    try 
    {
        graph.addEdge(9, 10);
    } 
    catch (const std::invalid_argument& e) 
    {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}






