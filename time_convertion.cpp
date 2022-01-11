#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
	vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = s.find(":", start)) != string::npos) {
        tokens.push_back(s.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(s.substr(start));

	int hh = stoi(tokens[0]);

	if((tokens[2].find("PM", 0)) != string::npos && hh != 12) {
		hh += 12;
		tokens[0] = to_string(hh);
	} else if((tokens[2].find("AM", 0)) != string::npos && hh == 12) {
		tokens[0] = "00";
	};

	tokens[2].erase(2, 3);

	string result;

	for(int i = 0; i < 2; ++i) {
		result += (tokens[i] + ':');
	}

	result += tokens[2];

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
