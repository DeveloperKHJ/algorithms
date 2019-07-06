//#include <stdio.h>
//// 백준 11726, 11727 문제
//int d[1001];
//
//int dp(int x) {
//	if (x == 1) return 1;
//	if (x == 2) return 3;
//	if (d[x] != 0) return d[x];
//	return d[x] = (dp(x - 1) + 2 * dp(x - 2)) % 10007;
//}
//
//int main(void) {
//
//	int x;
//	scanf_s("%d", &x);
//	printf("%d", dp(x));
//}

//// 백준 2133번 문제
//
//#include <stdio.h>
//
//int d[1001];
//
//int dp(int x) {
//	if (x == 0) return 1;
//	if (x == 1) return 0;
//	if (x == 2) return 3;
//	if (d[x] != 0) return d[x];
//	int result = 3 * dp(x - 2);
//	for (int i = 3; i <= x; i++) {
//		if (i % 2 == 0) {
//			result += 2 * dp(x - i);
//		}
//	}
//
//	return d[x] = result;
//}
//
//int main(void) {
//
//	int x;
//	scanf_s("%d", &x);
//	printf("%d", dp(x));
//}


// 백준 14852번 문제
#include <stdio.h>

int d[1001];

int dp(int x) {
	if (x == 0) return 1;
	if (x == 1) return 0;
	if (x == 2) return 3;
	if (d[x] != 0) return d[x];
	int result = 3 * dp(x - 2);
	for (int i = 3; i <= x; i++) {
		if (i % 2 == 0) {
			result += 2 * dp(x - i);
		}
	}

	return d[x] = result;
}

int main(void) {

	int x;
	scanf_s("%d", &x);
	printf("%d", dp(x));
}