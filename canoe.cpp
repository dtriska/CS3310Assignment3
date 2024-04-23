#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <limits>
#include <sstream>

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
    // Open the file for reading
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    // Read the size of the input matrix from the first line
    int n;
    inputFile >> n;

    // Read the cost matrix from the file
    vector<vector<int>> C;
    string line;
    getline(inputFile, line); // Consume the rest of the first line
    while (getline(inputFile, line)) {
        istringstream iss(line);
        vector<int> row;
        int cost;
        while (iss >> cost) {
            row.push_back(cost);
        }
        // Add zeroes to the front of the row if necessary
        while (row.size() < n) {
            row.insert(row.begin(), 0);
        }
        C.push_back(row);
    }

    // Close the input file
    inputFile.close();

    // Compute minimum cost of traveling from post 0 to each subsequent post
    unordered_map<int, int> minCost = computeMinimumCost(n, C);

    // Print the minimum cost of traveling from post 0 to each subsequent post
    for (int post = 1; post < n; ++post) {
        cout << "Minimum cost from post 0 to post " << post << ": " << minCost[post] << endl;
    }

    return 0;
}
