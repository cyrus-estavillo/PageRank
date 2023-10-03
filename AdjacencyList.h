//
// Created by Skyler Estavillo on 3/29/23.
//

#ifndef PAGERANK_ADJACENCYLIST_H
#define PAGERANK_ADJACENCYLIST_H

#endif //PAGERANK_ADJACENCYLIST_H

#include <iostream>
#include <string>
#include <functional>
#include <map>
#include <vector>
#include <iomanip>
using namespace std;

class AdjacencyList {
private:
    // Maps URLs to unique IDs in a sorted order (for output)
    map<string, unsigned int> url_to_id;
    // Store incoming links for each node/URL using unique links
    vector<vector<unsigned int>> in_links;
    // Store outgoing links for each node/URL using unique links
    vector<vector<unsigned int>> out_links;
    // Store PageRank values for each node/URL
    vector<double> ranks;
    // Keep track of total # of nodes
    unsigned int nodeCount;

public:
    // Constructor to initialize nodeCount, resize in_links and ranks
    AdjacencyList(int n);

    // Add a directed edge from the "from" URL to the "to" URL
    void addEdge(const string& from, const string& to);

    // Compute page rank after specified number of power iterations
    void pageRank(int powerIterations, std::ostream& out);
};