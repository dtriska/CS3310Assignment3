import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

public class Canoe {

    static final int INF = Integer.MAX_VALUE;

    // Function to compute the minimum cost of traveling from post 0 to each subsequent post
    static Map<Integer, Integer> computeMinimumCost(int n, int[][] C) {
        Map<Integer, Integer> minCost = new HashMap<>(); // Map to store minimum costs

        // Base case: Minimum cost from post 0 to post 0 is 0
        minCost.put(0, 0);

        // Loop through each post from 1 to n-1
        for (int post = 1; post < n; ++post) {
            int minCostToPost = INF; // Initialize minimum cost to post as infinity

            // Loop through each previous post from 0 to post-1
            for (int prevPost = 0; prevPost < post; ++prevPost) {
                // Calculate the cost of renting a canoe from prevPost to post
                int cost = C[prevPost][post];

                // Calculate the minimum cost from post 0 to prevPost and add the cost to reach post from prevPost
                int totalCost = minCost.get(prevPost) + cost;

                // Update the minimum cost to post by comparing it with the previous cheapest path
                minCostToPost = Math.min(minCostToPost, totalCost);
            }
            // Save the minimum cost to reach the current post in the map
            minCost.put(post, minCostToPost);
        }
        
        return minCost;
    }

    // Function to print the sequence of rentals for the route between posts 0 and n - 1
    static void printRentalSequence(Map<Integer, Integer> minCost, int n, int[][] C) {
        System.out.println("Sequence of Rentals:");
        int post = n - 1;
        while (post > 0) {
            for (int prevPost = 0; prevPost < post; ++prevPost) {
                int cost = minCost.get(post) - minCost.get(prevPost);
                if (C[prevPost][post] == cost) {
                    System.out.println("Rent canoe from post " + prevPost + " to post " + post + " (Cost: " + cost + ")");
                    post = prevPost;
                    break;
                }
            }
        }
    }
    

    public static void main(String[] args) {
        if (args.length != 1) {
            System.err.println("Usage: java Canoe <input_file>");
            System.exit(1);
        }

        String fileName = args[0];
        
        try (BufferedReader inputFile = new BufferedReader(new FileReader(fileName))) {
            // Read the size of the input matrix from the first line
            int n = Integer.parseInt(inputFile.readLine().trim());

            // Read the cost matrix from the file
            int[][] C = new int[n][n];
            for (int i = 0; i < n; i++) {
                String line = inputFile.readLine();
                if (line == null) {
                    break; // End of file reached
                }
                String[] parts = line.trim().split("\\s+");
                // Initialize row with zeroes
                int[] row = new int[n];
                for (int k = 0; k < n; k++) {
                    row[k] = 0;
                }
                // Copy values from file to the end of the row
                for (int j = 0; j < parts.length; j++) {
                    row[j + (n - parts.length)] = Integer.parseInt(parts[j]);
                }
                // Assign the row to the cost matrix
                C[i] = row;
            }

            // Compute minimum cost of traveling from post 0 to each subsequent post
            Map<Integer, Integer> minCost = computeMinimumCost(n, C);

            // Print the minimum cost of traveling from post 0 to each subsequent post
            for (int post = 1; post < n; ++post) {
                System.out.println("Minimum cost from post 0 to post " + post + ": " + minCost.get(post));
            }

            // Print the sequence of rentals for the route between posts 0 and n - 1
            printRentalSequence(minCost, n, C);
        } catch (IOException e) {
            System.err.println("Error: Unable to open input file.");
            e.printStackTrace();
        }
    }
}
