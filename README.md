# N.-First-words---Solution
This is my solution for the problem N of the Central Russia regional contest 2022, the problem N.

## Idea
I use the Knuth-Morris-Pratt Algorithm with BFS (Breadth First Search) for solve the problem N. 
If you want to know about how does it work my algorithm, first, I use the **KMP** for search all the positions with his length of each pattern. next, I use the BFS for visited all the nodes, if the last node is visited, then the answer is "YES", else, the answer is "NO".

## Links
- https://codeforces.com/gym/104805/problem/N
- https://www.prepbytes.com/blog/strings-interview-programming/kmp-algorithm-for-pattern-searching/
