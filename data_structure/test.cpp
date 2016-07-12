#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
//#include <conio>
using namespace std;

#define For(i,a,b) for(ll i = (a); i <= (b); i++)
#define Dow(i,a,b) for(ll i = (a); i >= (b); i--)
#define fill(a, x) memset(a, x, sizeof(a))
#define sz(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair <long long, long long> pll;
typedef pair <int, int > pii;

const int maxN = 1e5 + 100;
const int mod = 1e9 + 7;
const int inf = 1e9;

void swapp(int *a, int *b) {
	int c = *a;
	*a = *b;
	*b = c;
}

int main() {
	#ifndef ONLINE_JUDGE
	    freopen ("input.txt", "r", stdin);
	    // freopen("output.txt", "w", stdout);
	#endif
	ios :: sync_with_stdio(false);
	
	int a, b;
	a = 5; b = 6;
	swapp(&a, &b);
	cout << a << " " << b;
	
	return 0;
}

