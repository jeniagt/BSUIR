#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	cout << "string? ";
	getline(cin, s);

	int k;
	cout << "k? ";
	cin >> k;
	k--;
	string ss1;
	string ss2;

	if (k >= s.size() - 1) {
		ss1 = s;
	}
	else if (k == 0) {
		ss2 = s;
	}
	else if (s[k] != ' ') {
		while (s[k] != ' ') {
			k--;
			if (k == 0) {
				break;
			}
		}
		if (k != 0) k++;
		ss1 = s.substr(0, k);
		ss2 = s.substr(k);
	}
	else {
		k++;
		ss1 = s.substr(0, k);
		ss2 = s.substr(k);
	}
	cout << "substring 1: " << ss1 << endl;
	cout << "substring 2: " << ss2 << endl;

	return 0;

}