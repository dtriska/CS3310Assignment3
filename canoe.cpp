#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

// Function to compute the minimum cost of traveling from post 0 to each subsequent post
unordered_map<int, int> computeMinimumCost(int n, vector<vector<int>>& C) {
    unordered_map<int, int> minCost; // Hash table to store minimum costs

    // Base case: Minimum cost from post 0 to post 0 is 0
    minCost[0] = 0;

    // Loop through each post from 1 to n-1
    for (int post = 1; post < n; ++post) {
        int minCostToPost = INF; // Initialize minimum cost to post as infinity

        // Loop through each previous post from 0 to post-1
        for (int prevPost = 0; prevPost < post; ++prevPost) {
            // Calculate the cost of renting a canoe from prevPost to post
            int cost = C[prevPost][post];

            // If cost is not infinity
            if (cost != INF) {
                // Calculate the minimum cost from post 0 to prevPost and add the cost to reach post from prevPost
                int totalCost = minCost[prevPost] + cost;
                
                // Update the minimum cost to post by comparing it with the previous cheapest path
                minCostToPost = min(minCostToPost, totalCost);
            }
        }
        // Save the minimum cost to reach the current post in the hash table
        minCost[post] = minCostToPost;
    }

    return minCost;
}

int main() {
    // Sample cost matrix
    vector<vector<int>> C = {
        {0, 10, 50, 5, 12, 27},
        {INF, 0, 23, 16, 38, 44},
        {INF, INF, 0, 30, 15, 33},
        {INF, INF, INF, 0, 33, 43},
        {INF, INF, INF, INF, 0, 12},
        {INF, INF, INF, INF, INF, 0}
    };

    int n = C.size();

    // Compute minimum cost of traveling from post 0 to each subsequent post
    unordered_map<int, int> minCost = computeMinimumCost(n, C);

    // Print the minimum cost of traveling from post 0 to each subsequent post
    for (int post = 1; post < n; ++post) {
        cout << "Minimum cost from post 0 to post " << post << ": " << minCost[post] << endl;
    }

    return 0;
}
