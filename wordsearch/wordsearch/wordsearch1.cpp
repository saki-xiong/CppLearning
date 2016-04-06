#include<vector>
#include<string>
using namespace std;
//word search
class Solution{
public:
bool IsValid(vector<vector<char> >& board, int visit_x, int visit_y, vector<vector<bool> > &Visited)
{
	int m = board.size();
	int n = board[0].size();
	if (visit_x<0 || visit_x >= m || visit_y<0 || visit_y >= n || Visited[visit_x][visit_y])
		return false;
	return true;
}

bool dfs(int idx, string &word, int visit_x, int visit_y, vector<vector<char> >& board, vector<vector<bool> > &Visited)
{
	if (idx == word.length())
		return true;
	//idx++;
	Visited[visit_x][visit_y] = true;

	int dx[4] = { 0, 0, -1, 1 };
	int dy[4] = { 1, -1, 0, 0 };
	for (int mi = 0; mi<4; mi++)
	{
		int xx = visit_x + dx[mi];
		int yy = visit_y + dy[mi];
		if (IsValid(board, xx, yy, Visited) && board[xx][yy] == word[idx] && dfs(idx+1, word,  xx, yy, board, Visited))
			return true;
	}
	Visited[visit_x][visit_y] = false;
	return false;
}
bool exist(vector<vector<char>>& board, string word)
{
	if (word.empty()) return false;
	int m = board.size();
	if (m == 0) return false;
	int n = board[0].size();
	if (n == 0) return false;
	vector<vector<bool> > Visited(m, vector<bool>(n, false));
	for (int i = 0; i<m; i++)
	{
		for (int j = 0; j<n; j++)
		{
			if (board[i][j] == word[0] && dfs(1, word, i, j, board, Visited))
				return true;
		}
	}
	return false;
}

};

//wordsearch2