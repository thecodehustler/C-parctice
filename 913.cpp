#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<vector<int>>> Mem;

class Solution {
   public:
    int n = 0;

    int catMouseGame(vector<vector<int>> &graph) {
        n = graph.size();
        Mem mem = Mem(n * n * 2, vector<vector<int>>(n, vector<int>(n, -1)));
        return game(mem, 2, 1, 0, graph);
    }

    /**
     * This actually runs the game.
     * @param mem dfs memory map.
     * @param cat cat's position;
     * @param mouse mouse's position;
     * @param step starts from 0, odd means cat's turn; even means mouse's turn.
     */
    int game(Mem &mem, int cat, int mouse, int step,
             vector<vector<int>> &graph) {
        if (mouse == cat) return 2;       // cat meets mouse, cat wins.
        if (mouse == 0) return 1;         // mouse reaches hole, mouse wins.
        if (step >= n * 2 + 1) return 0;  // round draw.

        // If known.
        if (mem[step][cat][mouse] != -1) {
            return mem[step][cat][mouse];
        }

        if (step % 2 == 0) {
            // Turn for mouse.
            bool draw = false;
            for (int &next : graph[mouse]) {
                // search for a win approach
                int ret = game(mem, cat, next, step + 1, graph);
                if (ret == 1) {  // when mouse wins...
                    // we're being greedy here.
                    mem[step][cat][mouse] = 1;
                    return 1;  // return early.
                }
                if (ret == 0) draw = true;
            }
            if (draw) {  // mouse cannot win, but a draw is possible.
                mem[step][cat][mouse] = 0;
                return 0;
            }
            // mouse has no way out but lose.
            mem[step][cat][mouse] = 2;
            return 2;
        } else {  // Turn for cat. Basically the same logic as mouse's.
            bool draw = false;
            for (int &next : graph[cat]) {
                if (next == 0) continue;
                int ret = game(mem, next, mouse, step + 1, graph);
                if (ret == 2) {
                    mem[step][cat][mouse] = 2;
                    return 2;
                }
                if (ret == 0) draw = true;
            }

            if (draw) {
                mem[step][cat][mouse] = 0;
                return 0;
            }

            mem[step][cat][mouse] = 1;
            return 1;
        }
    }
};

vector<vector<int>> graph = {{2, 5},    {3},    {0, 4, 5},
                             {1, 4, 5}, {2, 3}, {0, 2, 3}};

int main() {
    Solution sln;
    return sln.catMouseGame(graph);
}