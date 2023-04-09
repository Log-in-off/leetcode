#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int largestPathValue(std::string colors, std::vector<std::vector<int>>& edges) {
        int n = colors.size();
        int k = 26;
        std::vector<int> indegrees(n, 0);
        std::vector<std::vector<int>> graph(n, std::vector<int>());
        for (std::vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            indegrees[v]++;
        }
        std::unordered_set<int> zero_indegree;
        for (int i = 0; i < n; i++) {
            if (indegrees[i] == 0) {
                zero_indegree.insert(i);
            }
        }
        std::vector<std::vector<int>> counts(n, std::vector<int>(k, 0));
        for (int i = 0; i < n; i++) {
            counts[i][colors[i] - 'a']++;
        }
        int max_count = 0;
        int visited = 0;
        while (!zero_indegree.empty()) {
            int u = *zero_indegree.begin();
            zero_indegree.erase(u);
            visited++;
            for (int v : graph[u]) {
                for (int i = 0; i < k; i++) {
                    counts[v][i] = std::max(counts[v][i], counts[u][i] + (colors[v] - 'a' == i ? 1 : 0));
                }
                indegrees[v]--;
                if (indegrees[v] == 0) {
                    zero_indegree.insert(v);
                }
            }
            max_count = std::max(max_count, *max_element(counts[u].begin(), counts[u].end()));
        }
        return visited == n ? max_count : -1;
    }
};

int main() 
{
    Solution a;
    {
        std::vector<std::vector<int>> edges = {{0,0}};
        std::string colors = "a";
        int answer = -1;
        assert(answer == a.largestPathValue(colors, edges));
    }
    {
        std::vector<std::vector<int>> edges = {{0,1},{0,2},{2,3},{3,4}};
        std::string colors = "abaca";
        int answer = 3;
        assert(answer == a.largestPathValue(colors, edges));
    }
    std::cout << "Test done" << std::endl;
    return 0;
}