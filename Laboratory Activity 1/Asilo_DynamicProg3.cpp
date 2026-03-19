#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printCombinations(vector<int>& candidates, int target) {
    vector<vector<vector<int>>> dp(target + 1);

    dp[0] = {{}};

    for (int c : candidates) {
        for (int i = c; i <= target; ++i) {
            for (vector<int> comb : dp[i - c]) {
                comb.push_back(c); 
                dp[i].push_back(comb); 
            }
        }
    }

    if (!dp[target].empty()) {
        cout << "Combinations are:" << endl;
        
        vector<vector<int>> result = dp[target];
        sort(result.begin(), result.end());

        for (const auto& comb : result) {
            cout << "{ ";
            for (int num : comb) {
                cout << num << " ";
            }
            cout << "}" << endl;
        }
    }
}

int main() {
    int n;
    cout << "Enter number of candidates: ";
    cin >> n;

    vector<int> candidates(n);
    cout << "Enter the candidates: ";
    for (int i = 0; i < n; ++i) {
        cin >> candidates[i];
    }

    int target;
    cout << "Enter the target: ";
    cin >> target;

    sort(candidates.begin(), candidates.end());
    candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());

    printCombinations(candidates, target);

    return 0;
}