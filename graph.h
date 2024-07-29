/***************************************
* Name: Jon Welch
* Assignment: Final Project
* Purpose of the file: This header file contains the definition of the Node and Graph classes.
* It declares the Graph class methods and attributes.
*
* @note This file is associated with [graph.cpp]
***************************************/

#ifndef GRAPH_H
#define GRAPH_H

#include <stack>
#include <queue>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <stdexcept>
#include "function.h"

using std::vector;
using std::unordered_map;
using std::unordered_set;
using std::string;
using std::stack;
using std::queue;
using std::cout;
using std::endl;


class Node
{
    /*********************************************
    This class defines a Node. It represents a node in an undirected graph.
    The class has methods to access and update node data and neighbors.
    
    @attrib id : unique identifier for the node
    @attrib data : data associated with the node
    @attrib neighbors : list of neighbor node ids
    *********************************************/
    private:
    int id;
    string data;
    vector<int> neighbors; 
    
    public:
    /**********************
    Constructors/Destructor
    ***********************/
    Node(int, const string&);
    ~Node();

    /**********************
    Getters/Accessors
    ***********************/
    int getId() const;
    string getData() const;
    const vector<int>& getNeighbors() const;

    /**********************
    Setters/Mutators
    ***********************/
    void addNeighbor(int);
    bool hasNeighbor(int) const;

};

class Graph
{
    /*********************************************
    This class defines a Graph. It represents an undirected, unweighted graph.
    The class has methods to add nodes, add edges, check for cycles, and perform
    depth-first and breadth-first searches.
    @attrib nodes : map of node ids to Node pointers
    *********************************************/
    private:
    unordered_map<int, Node*> nodes;
    bool hasCycleUtil(int, unordered_set<int>&, int);
    
    public:
    /**********************
    Constructors/Destructor
    ***********************/
    Graph();
    ~Graph();

    /**********************
    Setters/Mutators
    ***********************/
    void addNode(int, const string&);
    void addEdge(int, int);

    /**********************
    Getters/Accessors
    ***********************/
    Node* getNode(int);
    vector<Node*> getNodes() const;

    /**********************
    Helper Methods
    ***********************/
    bool hasCycle();
    void dfs(int, vector<int>&);
    void bfs(int, vector<int>&);
    bool hasEdge(int, int) const; 

};

#endif // GRAPH_H
