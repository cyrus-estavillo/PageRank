//
// Created by Skyler Estavillo on 3/29/23.
//
#include <iostream>
#include "AdjacencyList.h"


AdjacencyList::AdjacencyList(int n) {
    nodeCount = 0;

    // This resizing seems to work fine for test cases, but what if every link
    // features two unique URLs, and the graph isn't really connected? Will this cause a problem?
    in_links.resize(0);
    out_links.resize(0);
    ranks.resize(0, 0.0);
}

void AdjacencyList::addEdge(const string& from, const string& to)
{
    int from_id, to_id;

    // If the 'from' URL is not in the map, add it. Else, assign it the proper ID
    if (url_to_id.find(from) == url_to_id.end()) {
        from_id = nodeCount++;
        url_to_id[from] = from_id;
    }
    else
    {
        from_id = url_to_id[from];
    }

    // If the 'to' URL is not in the map, add it. Else, assign it the proper ID
    if (url_to_id.find(to) == url_to_id.end()) {
        to_id = nodeCount++;
        url_to_id[to] = to_id;
    }
    else
    {
        to_id = url_to_id[to];
    }

    // Resize the in_links and out_links vectors to fit the new nodes
    if (nodeCount > in_links.size() || nodeCount > out_links.size())
    {
        in_links.resize(nodeCount);
        out_links.resize(nodeCount);
    }

    // Add the "to" URL to the "from" URL's in_links
    in_links[to_id].push_back(from_id);
    // Add the "from" URL to the "to" URL's out_links
    out_links[from_id].push_back(to_id);
}



/*
 // prints the PageRank of all pages after p powerIterations in ascending
    alphabetical order of webpages and rounding rank to two decimal places
 */
void AdjacencyList::pageRank(int powerIterations, std::ostream& out)
{
    // Resize the ranks vector at last second to fit the new nodes
    ranks.resize(nodeCount, 1.0 / nodeCount);

    // Perform the specified number of power iterations
    // Power iterations between 1 <= p < 10,000
    for (unsigned int i = 1; i < powerIterations; i++)
    {
        // Create a temporary vector to store the new ranks
        vector<double> new_ranks(nodeCount, 0.0);

        // For each node, calculate the new rank
        for (unsigned int to_id = 0; to_id < nodeCount; to_id++)
        {
            // For each node that has an incoming link to the current node
            for (unsigned int from_id : in_links[to_id])
            {
                // Add the current node's rank divided by the number of
                // outgoing links to the temporary vector
                new_ranks[to_id] += ranks[from_id] * (1.0 / out_links[from_id].size());
            }
        }

        // Update the ranks vector with the new ranks
        ranks.swap(new_ranks);
    }

    // Set the output format for floating point values for ranks
    out << std::fixed << setprecision(2);

    // Print the ranks in ascending alphabetical order
    for (auto it = url_to_id.begin(); it != url_to_id.end(); it++)
    {
        out << it->first << " " << ranks[it->second] << std::endl;
    }
}