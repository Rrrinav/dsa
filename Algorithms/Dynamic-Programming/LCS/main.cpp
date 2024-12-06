#include <iostream>
#include <string>
#include <vector>

using namespace std;

int LCS(string X, string Y)
{
  int m = X.length();
  int n = Y.length();

  // Create a 2D table to store lengths of longest common subsequence.
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

  // Build the dp table in bottom-up fashion
  for (int i = 1; i <= m; i++)
  {
    for (int j = 1; j <= n; j++)
      if (X[i - 1] == Y[j - 1])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
  }

  // The length of LCS is stored in dp[m][n]
  return dp[m][n];
}

// Function to print the LCS using the dp table
string print_LCS(string X, string Y)
{
  int m = X.length();
  int n = Y.length();
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

  // Build the dp table in bottom-up fashion
  for (int i = 1; i <= m; i++)
  {
    for (int j = 1; j <= n; j++)
      if (X[i - 1] == Y[j - 1])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
  }

  cout << "   ";
  for (int i = 0; i <= m + 1; i++) cout << i << " ";

  cout << endl << endl;
  int cn = 0;
  for (auto &row : dp)
  {
    cout << cn << "  ";
    for (auto &cell : row) cout << cell << " ";
    cout << endl;
    cn++;
  }

  // Backtrack to find the LCS
  string lcs = "";
  int i = m, j = n;

  while (m > 0 && n > 0)
  {
    cout << "At dp[" << m << "][" << n << "] -> Comparing X[" << m - 1 << "] = " << X[m - 1] << " with Y[" << n - 1 << "] = " << Y[n - 1]
         << endl;

    if (X[m - 1] == Y[n - 1])
    {
      // Characters match, add to LCS
      cout << "Characters match: " << X[m - 1] << ". Adding to LCS." << endl;
      lcs = X[m - 1] + lcs;
      m--;
      n--;
    }
    else
    {
      // Characters do not match, move in the direction of the larger value
      if (dp[m - 1][n] >= dp[m][n - 1])
      {
        cout << "Characters do not match. Moving up to dp[" << m - 1 << "][" << n << "]" << endl;
        m--;
      }
      else
      {
        cout << "Characters do not match. Moving left to dp[" << m << "][" << n - 1 << "]" << endl;
        n--;
      }
    }
    cout << "Current LCS: " << lcs << endl;
  }

  return lcs;
}

int main()
{
  string X = "AGGTAB";
  string Y = "GXTXAYB";

  // Find length of LCS
  int length = LCS(X, Y);
  cout << "Length of Longest Common Subsequence: " << length << endl;

  // Print the LCS itself
  string lcs = print_LCS(X, Y);
  cout << "Longest Common Subsequence: " << lcs << endl;

  return 0;
}
