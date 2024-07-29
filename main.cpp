/***********************************************
* Name: Jon Welch
* Assignment: Final Project
* Purpose of the file: This source file contains the main function for testing the Graph class.
* It generates test data, inserts it into the graph, and demonstrates various operations.
* 
* @note This file is associated with [main.h]
***********************************************/

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
    @note : More than one scope, 2 in total; 
    *********************************************/

    srand(static_cast<unsigned int>(time(0)));

    //[Scope 1] Tests
    {
        Graph graph;
        cout << endl << "Graph created" << endl << endl;

        /*********************************************
        Testing addNode and addEdge methods
        *********************************************/
        cout << "Testing addNode() and addEdge()" << endl;
        cout << "==============================================" << endl;

        int ids1[NUMNODES] = {1, 2, 3, 4, 5, 6, 7};
        string strings1[NUMNODES] = {"Node 1", "Node 2", "Node 3", "Node 4", "Node 5", "Node 6", "Node 7"};

        for (int i = 0; i < NUMNODES; i++)
        {
            graph.addNode(ids1[i], strings1[i]);
            cout << "Added node " << ids1[i] << " with data: " << strings1[i] << endl;
        }

        int edges[7][2] = {{1, 2}, {1, 3}, {2, 4}, {2, 5}, {3, 6}, {3, 7}, {4, 7}};

        for (int i = 0; i < NUMNODES; i++)
        {
            graph.addEdge(edges[i][0], edges[i][1]);
            cout << "Added edge between " << edges[i][0] << " and " << edges[i][1] << endl;
        }

        cout << endl;

        /*********************************************
        Testing getNode and getNodes methods
        *********************************************/
        cout << "Testing getNode() and getNodes()" << endl;
        cout << "==============================================" << endl;

        for (int i = 0; i < NUMNODES; i++)
        {
            Node* node = graph.getNode(ids1[i]);
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
        Testing hasCycle method
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
        Testing DFS and BFS methods
        *********************************************/
        cout << "Testing DFS and BFS" << endl;
        cout << "==============================================" << endl;

        cout << "Performing DFS starting from node 1:" << endl;
        vector<int> expectedDfsOrder = {1, 2, 4, 7, 3, 6, 5};
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
        vector<int> expectedBfsOrder = {1, 2, 3, 7, 4, 5, 6};
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
        Additional Testing for Edge Cases
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
    }

    //[Scope 2] Tests
    {
        Graph graph;
        cout << endl << "Random Graph created" << endl << endl;

        for (int i = 1; i <= NUMNODES; i++)
        {
            string nodeData = "Node " + std::to_string(i);
            graph.addNode(i, nodeData);
            cout << "Added node " << i << " with data: " << nodeData << endl;
        }

        //adding random edges
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
        /*********************************************
        Ensure all nodes are connected
        *********************************************/
        for (int i = 1; i < NUMNODES; i++)
        {
            for (int j = i + 1; j <= NUMNODES; j++)
            {
                if (!graph.hasEdge(i, j))
                {
                    graph.addEdge(i, j);
                    cout << "Added edge between " << i << " and " << j << " to ensure full connectivity." << endl;
                }
            }
        }

        cout << endl;

        /*********************************************
        Testing DFS and BFS methods
        *********************************************/
        cout << "Testing DFS and BFS on Random Graph" << endl;
        cout << "==============================================" << endl;

        cout << "Performing DFS starting from node 1:" << endl;
        vector<int> actualDfsOrder;
        graph.dfs(1, actualDfsOrder);
        cout << "DFS order: ";
        for (int id : actualDfsOrder) cout << id << " ";
        cout << endl;

        cout << "Performing BFS starting from node 1:" << endl;
        vector<int> actualBfsOrder;
        graph.bfs(1, actualBfsOrder);
        cout << "BFS order: ";
        for (int id : actualBfsOrder) cout << id << " ";
        cout << endl;

        // Validate traversals
        assert(!actualDfsOrder.empty() && actualDfsOrder[0] == 1);
        assert(!actualBfsOrder.empty() && actualBfsOrder[0] == 1);
        assert(actualDfsOrder.size() == NUMNODES);
        assert(actualBfsOrder.size() == NUMNODES);

        cout << "DFS and BFS traversals on random graph are valid." << endl;
    }
    // [Scope 3]Additional edge cases
    {
        Graph graph;
        cout << endl << "Additional Edge Cases" << endl << endl;

        // Test duplicate edges
        graph.addNode(1, "Node 1");
        graph.addNode(2, "Node 2");
        graph.addEdge(1, 2);
        graph.addEdge(1, 2);  // Duplicate edge

        // Test isolated nodes
        graph.addNode(3, "Node 3");
        vector<int> isolatedNodeDfsOrder;
        graph.dfs(3, isolatedNodeDfsOrder);
        assert(isolatedNodeDfsOrder.size() == 1 && isolatedNodeDfsOrder[0] == 3);
        vector<int> isolatedNodeBfsOrder;
        graph.bfs(3, isolatedNodeBfsOrder);
        assert(isolatedNodeBfsOrder.size() == 1 && isolatedNodeBfsOrder[0] == 3);

        cout << "Duplicate edges and isolated nodes handled correctly." << endl;
    }

    //[Scope 4] Performance test with a large graph
    {
        Graph largeGraph;
        cout << endl << "Performance Test with Large Graph" << endl << endl;

        for (int i = 1; i <= LARGE_NUM_NODES; ++i)
        {
            largeGraph.addNode(i, "Node " + std::to_string(i));
        }

        for (int i = 1; i < LARGE_NUM_NODES; ++i)
        {
            largeGraph.addEdge(i, i + 1);
        }

        vector<int> largeGraphDfsOrder;
        largeGraph.dfs(1, largeGraphDfsOrder);
        assert(largeGraphDfsOrder.size() == LARGE_NUM_NODES);

        vector<int> largeGraphBfsOrder;
        largeGraph.bfs(1, largeGraphBfsOrder);
        assert(largeGraphBfsOrder.size() == LARGE_NUM_NODES);

        cout << "Large graph handled correctly." << endl;
    }
    return 0;
}
