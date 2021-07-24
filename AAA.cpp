#include<iostream>
#include<fstream>
#include<ctime>
#include<vector>
#include<algorithm>

using namespace std;

void matr(vector<vector<int>>& a, int n,int m) {
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = rand() % 10;
		}
	}
}
void out(vector<vector<int>>& a,int n,int m) {
	for (int i = 0; i <n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << '\t';
		}
		cout << endl;
	}
}
void out(vector<int>& a) {
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << '\t';
	}
}
int fillfile(ofstream& f) {
	srand(time(NULL));
	int c = rand() % 20;
	for (int i = 0; i < c; i++) {
		f << rand() % 10 << ' ';
	}
	return c;
}
void read(ifstream& g, vector<int>& a) {
	for (int i = 0; i < a.size(); i++) {
		g >> a[i];
	}
}
void del(vector<int>& a) {
	cout << endl;
	for (int i = 0; i < a.size(); i++) {
		if (a.size() == i + 1) break;
		if (a[i] == a[i+1] ) {
			a.erase(a.begin()+i);
			i--;
		}
	}	
}
int main() {
	ofstream f;
	f.open("chisla.txt");
	vector<int> a(fillfile(f));
	f.close();
	ifstream g;
	g.open("chisla.txt");
	read(g, a);
	g.close();
	out(a);
	cout << "\n\n";
	sort(a.begin(), a.end());
	del(a);
	out(a);
}
