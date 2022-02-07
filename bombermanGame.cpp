#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'bomberMan' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING_ARRAY grid
 */

vector<string> bomberMan(int n, vector<string> grid) {
	size_t vec_size = grid.size();
	size_t str_size = grid[0].size();
	for(int turn = 0; turn <= n; ++ turn) {
		for(size_t i = 0; i < vec_size; ++i) {
			for(size_t j = 0; j < str_size; ++j) {
				if(grid[i][j] == 'O')
					grid[i][j] = '3';
				
				if(grid[i][j] != '.' && grid[i][j] - '0' == turn) {
					grid[i][j] = '.';
					if(i > 0)
						grid[i-1][j] = '.';
					if(i < vec_size-1 && grid[i+1][j] -'0' != turn)
						grid[i+1][j] = '.';
					if(j > 0)
						grid[i][j-1] = '.';
					if(j < str_size-1 && grid[i][j+1] -'0' != turn)
						grid[i][j+1] = '.';
				}

				if(turn != 0 && !(turn % 2)) {
					if(grid[i][j] == '.')
						grid[i][j] = '0' + turn + 3;
				}
			}
		}
	}

	for(size_t i = 0; i < vec_size; ++i) {
		for(size_t j = 0; j < str_size; ++j) {
			if(grid[i][j] != '.')
				grid[i][j] = 'O';
		}
	}

	return grid;
}

int main()
{
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int r = stoi(first_multiple_input[0]);

    int c = stoi(first_multiple_input[1]);

    int n = stoi(first_multiple_input[2]);

    vector<string> grid(r);

    for (int i = 0; i < r; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = bomberMan(n, grid);

    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
