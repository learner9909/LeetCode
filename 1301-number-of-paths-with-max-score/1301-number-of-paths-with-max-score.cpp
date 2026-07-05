#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        const int MOD = 1e9 + 7;
        
        vector<vector<int>> score(n, vector<int>(n, -1));
        vector<vector<int>> ways(n, vector<int>(n, 0));
        
        // Start from 'E' (bottom-right)
        score[n-1][n-1] = 0;
        ways[n-1][n-1] = 1;
        
        for (int i = n-1; i >= 0; --i) {
            for (int j = n-1; j >= 0; --j) {
                if (board[i][j] == 'X' || (i == n-1 && j == n-1)) continue;
                
                int best = -1;
                long long cnt = 0;
                
                // Check three possible moves
                for (auto [dx, dy] : vector<pair<int,int>>{{1,0},{0,1},{1,1}}) {
                    int ni = i + dx, nj = j + dy;
                    if (ni < n && nj < n && score[ni][nj] != -1) {
                        if (score[ni][nj] > best) {
                            best = score[ni][nj];
                            cnt = ways[ni][nj];
                        } else if (score[ni][nj] == best) {
                            cnt = (cnt + ways[ni][nj]) % MOD;
                        }
                    }
                }
                
                if (best != -1) {
                    score[i][j] = best + (isdigit(board[i][j]) ? board[i][j] - '0' : 0);
                    ways[i][j] = cnt % MOD;
                }
            }
        }
        
        if (score[0][0] == -1) return {0,0};
        return {score[0][0], ways[0][0]};
    }
};
