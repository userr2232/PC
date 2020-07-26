#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int sx(0), sy(0), sz(0);
	while(n--) {
		int x, y, z;
		cin >> x >> y >> z;
		sx += x;
		sy += y;
		sz += z;
	}
	if(sx == 0 && sy == 0 && sz == 0)
		cout << "YES" << endl;
	else 
		cout << "NO" << endl;

	return 0;
}