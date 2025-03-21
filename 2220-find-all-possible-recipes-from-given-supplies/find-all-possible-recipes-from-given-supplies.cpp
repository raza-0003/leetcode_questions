#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_set<string> available;  // Stores available supplies
    unordered_map<string, vector<string>> graph; // Dependency graph
    unordered_map<string, int> visited; // To detect cycles

    bool canMake(string recipe) {
        if (available.count(recipe)) return true;  // If already available, return true
        if (!graph.count(recipe)) return false;   // If not in graph, can't make it
        if (visited[recipe] == 1) return false;   // Cycle detected (recipe depends on itself)
        if (visited[recipe] == 2) return true;    // Already computed and possible

        visited[recipe] = 1;  // Mark as visiting

        for (string &ingredient : graph[recipe]) {
            if (!canMake(ingredient)) return false; // If any ingredient is missing, can't make the recipe
        }

        visited[recipe] = 2;  // Mark as processed
        available.insert(recipe);  // Now it's available
        return true;
    }

    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        available = unordered_set<string>(supplies.begin(), supplies.end());  // Initialize available supplies

        for (int i = 0; i < recipes.size(); i++) {
            graph[recipes[i]] = ingredients[i];  // Build the dependency graph
        }

        vector<string> result;
        for (string &recipe : recipes) {
            if (canMake(recipe)) {
                result.push_back(recipe);
            }
        }

        return result;
    }
};