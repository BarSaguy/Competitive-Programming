#include <bits/stdc++.h>
 
using namespace std;
 
 
int main() {
    ios_base::sync_with_stdio(false);
	long long x1, y1, xn, yn, length, xdiff, ydiff;
    long long initial_x1, initial_y1;
	long long dist1, dist0;
	string s;
	cin >> x1 >> y1;
	cin >> xn >> yn;
	cin >> length;
	cin >> s;
 
	long long count = 0, count1;
 	initial_x1 = x1;
    initial_y1 = y1;

	for (int i = 0; i < length; i++) {
		if (s[i] == 'U') {
			y1++;
		}
		else if (s[i] == 'D') {
			y1--;
		}
		else if (s[i] == 'R') {
			x1++;
		}
		else if (s[i] == 'L') {
			x1--;
		}
		if (abs(xn - x1) + abs(yn - y1) <= i + 1LL) {
			cout << i + 1;
			return 0;
		}
	}

	xdiff = x1 - initial_x1;
	ydiff = y1 - initial_y1;
    bool found = false;
    long long start=0LL, end=1e10, mid, mid2;
	while (start < end) {
        mid = (end + start) / 2;
        mid2 = mid - 1LL;


		x1 = initial_x1 + mid * xdiff;
		y1 = initial_y1 + mid * ydiff;
        dist0 = abs(xn - x1) + abs(yn - y1);

        x1 = initial_x1 + mid2 * xdiff;
		y1 = initial_y1 + mid2 * ydiff;
		dist1 = abs(xn - x1) + abs(yn - y1);

        count = mid * length;
        count1 = mid2 * length;
		if (dist0 <= count && dist1 > count1) {
            found = true;
			break;
		}
        else if(dist0 > count)
            start = mid + 1;
        else
            end = mid;  
	}
    if(!found){
        cout << -1 << "\n";
        return 0;
    }
	x1 = initial_x1 + mid2 * xdiff;
	y1 = initial_y1 + mid2 * ydiff;
	count = mid2 * length;
	for (int i = 0; i < length; i++) {
		if (s[i] == 'U') {
			y1++;
		}
		else if (s[i] == 'D') {
			y1--;
		}
		else if (s[i] == 'R') {
			x1++;
		}
		else if (s[i] == 'L') {
			x1--;
		}
		if (abs(xn - x1) + abs(yn - y1) <= count + i + 1LL) {
			cout << count + i + 1;
			return 0;
		}
	}
 
	return 0;
}