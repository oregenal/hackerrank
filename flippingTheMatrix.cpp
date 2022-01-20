#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



/*
 * Complete the 'flippingMatrix' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY matrix as parameter.
 */

int flippingMatrix(vector<vector<int>> matrix) {
	size_t size = matrix[0].size();

	for(size_t i = 0; i < size; ++i) {
		int first_summ = 0;
		for(size_t j = 0; j < size/2; ++j) {
			first_summ += matrix[i][j];
		}

		int second_summ = 0;
		for(size_t j = size/2; j < size; ++j) {
			second_summ += matrix[i][j];
		}
		
		if(first_summ < second_summ) {
			reverse(matrix[i].begin(), matrix[i].end());
		}
	}

	for(size_t i = 0; i < size; ++i) {
		int first_summ = 0;
		for(size_t j = 0; j < size/2; ++j) {
			first_summ += matrix[j][i];
		}

		int second_summ = 0;
		for(size_t j = size/2; j < size; ++j) {
			second_summ += matrix[j][i];
		}
		
		if(first_summ < second_summ) {
			for(size_t j = 0; j < size/2; ++j) {
				int tmp = matrix[j][i];
				matrix[j][i] = matrix[size-j][i];
				matrix[size-j][i] = tmp;
			}
		}
	}

	int res = 0;
	for(size_t i = 0; i < size/2; ++i){
		for(size_t j = 0; j < size/2; ++j) {
			res += matrix[i][j];
		}
	}
	
	return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        vector<vector<int>> matrix(2 * n);

        for (int i = 0; i < 2 * n; i++) {
            matrix[i].resize(2 * n);

            string matrix_row_temp_temp;
            getline(cin, matrix_row_temp_temp);

            vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

            for (int j = 0; j < 2 * n; j++) {
                int matrix_row_item = stoi(matrix_row_temp[j]);

                matrix[i][j] = matrix_row_item;
            }
        }

        int result = flippingMatrix(matrix);

        fout << result << "\n";
    }

    fout.close();

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
