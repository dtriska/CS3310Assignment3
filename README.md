# CS3310Assignment3

This Java program calculates the minimum cost of traveling from the starting point (post 0) to each subsequent post along a canoe trip route. It reads the cost matrix from an input file and uses dynamic programming to compute the minimum costs.

## How to Compile

To compile the program, you need to have JDK (Java Development Kit) installed on your system.

Open a terminal or command prompt and navigate to the directory containing the `Canoe.java` file.

Compile the program using the `javac` command:

javac canoe.java

## How to Run

After compiling the program, you can run it using the `java` command followed by the name of the main class (`Canoe`):

java Canoe

The program expects an input file named `input.txt` in the same directory, containing the cost matrix. Each row of the matrix should be on a separate line, with values separated by whitespace.

Example `input.txt`:

 6
 1 25 35 23 50
    1 33 44 20
       1 34 44
          1 24
             1

The first line specifies the size of the matrix (`n`), followed by `n-1` lines representing the rows of the cost matrix.

## Output

The program prints the minimum cost of traveling from post 0 to each subsequent post, one per line, in the format:

For example:
Minimum cost from post 0 to post 1: 10
Minimum cost from post 0 to post 2: 33
Minimum cost from post 0 to post 3: 5
Minimum cost from post 0 to post 4: 12
Minimum cost from post 0 to post 5: 24







