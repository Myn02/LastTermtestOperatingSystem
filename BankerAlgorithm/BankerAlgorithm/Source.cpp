#include <iostream>
using namespace std;

int main()
{
	// P0, P1, P2 are the Process names here

	int n, m, i, j, k;
	n = 3; // Number of processes
	m = 4; // Number of resources
	int alloc[3][4] = { { 0, 0, 1, 2 }, // P0 // Allocation Matrix
						{ 1, 3, 0, 0 }, // P1
						{ 1, 3, 5, 5 }, };// P2  

	int max[3][4] = { { 3, 0, 1, 2 }, // P0 // MAX Matrix
					{ 1, 7, 5, 0 }, // P1
					{ 1, 3, 5, 5 }, // P2
	};

	int avail[4] = { 1, 5, 2, 0 }; // Available Resources

	int f[3], ans[3], ind = 0;
	for (k = 0; k < n; k++) {
		f[k] = 0;
	}
	int need[3][4];
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			need[i][j] = max[i][j] - alloc[i][j]; //Find Need's value
	}
	int y = 0;
	for (k = 0; k < m; k++) {
		for (i = 0; i < n; i++) {
			if (f[i] == 0) {

				int flag = 0;
				for (j = 0; j < m; j++) {
					if (need[i][j] > avail[j]) {
						flag = 1;
						break;
					}
				}

				if (flag == 0) {
					ans[ind++] = i;
					for (y = 0; y < m; y++)
						avail[y] += alloc[i][y];
					f[i] = 1;
				}
			}
		}
	}

	cout << "Following is the SAFE Sequence:" << endl;
	for (i = 0; i < n - 1; i++)
		cout << " P" << ans[i] << " ->";
	cout << " P" << ans[n - 1] << endl;

	return 0;
}
