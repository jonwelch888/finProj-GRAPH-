/*********************************************
* Name: Jon Welch
* Assignment: Final Project
* Purpose of the file: This source file contains the implementation of the Node and Graph classes.
* It handles operations such as adding nodes, adding edges, detecting cycles,
* and performing DFS and BFS.
*
* @note This file is associated with [graph.h]
*********************************************/

#include "graph.h"

Node::Node(int id, const string& data) : id(id), data(data)
{
    /*********************************************
    * Constructor to initialize the Node with given id and data.
    *
    * @param id : unique identifier for the node
    * @param data : data associated with the node
    *********************************************/
}

Node::~Node()
{
    /*********************************************
    * Destructor for Node class.
    * Currently no dynamic memory to clean up.
    *********************************************/
}

int Node::getId() const
{
    /*********************************************
    * getId: Returns the id of the node.
    * @return : id of the node
    *********************************************/
    return id;
}

string Node::getData() const
{
    /*********************************************
    * getData: Returns the data of the node.
    * @return : data of the node
    *********************************************/
    return data;
}

const vector<int>& Node::getNeighbors() const
{
    /*********************************************
    * getNeighbors: Returns a const reference to the neighbors vector.
    * @return : const reference to the neighbors vector
    *********************************************/
    return neighbors;
}

void Node::addNeighbor(int neighborId)
{
    /*********************************************
    * addNeighbor: Adds a neighbor to the node.
    * @param neighborId : id of the neighbor node to add
    *********************************************/
    neighbors.push_back(neighborId);
}

Graph::Graph()
{
    /*********************************************
    * Constructor to initialize an empty graph.
    *********************************************/
}

Graph::~Graph()
{
    /*********************************************
    * Destructor to clean up dynamically allocated memory.
    *********************************************/
    for (auto& pair : nodes)
    {
        delete pair.second;
    }
}

void Graph::addNode(int id, const string& data)
{
    /*********************************************
    * addNode: Adds a new node to the graph.
    * @param id : unique identifier for the node
    * @param data : data associated with the node
    *********************************************/
    if (nodes.find(id) == nodes.end())
    {
        nodes[id] = new Node(id, data);
    }
}

void Graph::addEdge(int id1, int id2)
{
    /*********************************************
    * addEdge: Adds an edge between two nodes in the graph.
    * @param id1 : id of the first node
    * @param id2 : id of the second node
    * @throws : std::invalid_argument if either id1 or id2 does not exist
    *********************************************/
    if (nodes.find(id1) == nodes.end() || nodes.find(id2) == nodes.end())
    {
        throw std::invalid_argument("One or both node ids do not exist");
    }
    nodes[id1]->addNeighbor(id2);
    nodes[id2]->addNeighbor(id1);
}

Node* Graph::getNode(int id)
{
    /*********************************************
    * getNode: Returns a pointer to the node with the given id.
    * @param id : id of the node to retrieve
    * @return : pointer to the node, or nullptr if not found
    *********************************************/
    return (nodes.find(id) != nodes.end()) ? nodes[id] : nullptr;
}

vector<Node*> Graph::getNodes() const
{
    /*********************************************
    * getNodes: Returns a vector of all nodes in the graph.
    * @return : vector of all nodes
    *********************************************/
    vector<Node*> result;
    for (const auto& pair : nodes)
    {
        result.push_back(pair.second);
    }
    return result;
}

bool Graph::hasCycleUtil(int nodeId, unordered_set<int>& visited, int parentId)
{
    /*********************************************
    * hasCycleUtil: Utility function to detect cycle in the graph.
    * @param nodeId : id of the current node
    * @param visited : set of visited nodes
    * @param parentId : id of the parent node
    * @return : true if a cycle is detected, false otherwise
    *********************************************/
    visited.insert(nodeId);
    bool hasCycle = false;
    for (int neighborId : nodes[nodeId]->getNeighbors())
    {
        if (visited.find(neighborId) == visited.end())
        {
            hasCycle = hasCycleUtil(neighborId, visited, nodeId);
        }
        else if (neighborId != parentId)
        {
            hasCycle = true;
        }
        if (hasCycle)
        {
            break;
        }
    }
    return hasCycle;
}

bool Graph::hasCycle()
{
    /*********************************************
    * hasCycle: Checks if the graph contains a cycle.
    * @return : true if a cycle is detected, false otherwise
    *********************************************/
    unordered_set<int> visited;
    bool hasCycle = false;
    for (const auto& pair : nodes)
    {
        if (visited.find(pair.first) == visited.end())
        {
            hasCycle = hasCycleUtil(pair.first, visited, -1);
            if (hasCycle)
            {
                break;
            }
        }
    }
    return hasCycle;
}


void Graph::dfs(int startId, vector<int>& order)
{
    /*********************************************
    dfs: Performs a depth-first search starting from the given node id.
    This function traverses the graph using DFS and stores the order of visited nodes.

    @param startId : id of the starting node
    @param order : reference to a vector where the order of visited nodes will be stored
    *********************************************/    
    if (nodes.find(startId) == nodes.end())
    {
        return;
    }
    unordered_set<int> visited;
    stack<int> stack;
    stack.push(startId);

    while (!stack.empty())
    {
        int nodeId = stack.top();
        stack.pop();

        if (visited.find(nodeId) == visited.end())
        {
            visited.insert(nodeId);
            order.push_back(nodeId);
            cout << "Visited node " << nodeId << endl;

            //neighbors and sort them using tSort
            vector<int> neighbors = nodes[nodeId]->getNeighbors();
            tSort(neighbors, neighbors.size());

            for (int neighborId : neighbors)
            {
                if (visited.find(neighborId) == visited.end())
                {
                    stack.push(neighborId);
                }
            }
        }
    }
}


void Graph::bfs(int startId, vector<int>& order)
{
    /*********************************************
    bfs: Performs a breadth-first search starting from the given node id.
    @param startId : id of the starting node
    @param order : reference to a vector where the order of visited nodes will be stored
    *********************************************/
    if (nodes.find(startId) == nodes.end())
    {
        return;
    }
    
    unordered_set<int> visited;
    queue<int> queue;
    queue.push(startId);
    
    while (!queue.empty())
    {
        int nodeId = queue.front();
        queue.pop();
        
        if (visited.find(nodeId) == visited.end())
        {
            visited.insert(nodeId);
            order.push_back(nodeId); // sstore order
            cout << "Visited node " << nodeId << endl;
            
            for (int neighborId : nodes[nodeId]->getNeighbors())
            {
                if (visited.find(neighborId) == visited.end())
                {
                    queue.push(neighborId);
                }
            }
        }
    }
}
