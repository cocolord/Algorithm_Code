#include<iostream>
#include<algorithm>
using namespace std;
long long  quickpow(long long   m, long long   n, long long k = 10);
int main()
{
	int n;
	int ans = 0;
	cin >> n;
	ans = quickpow(n, n);
	cout << ans << endl;
}

long long  quickpow(long long   m, long long   n, long long k = 10) {
	long long  ans = 1;
	//m是底数，n是指数
	while (n) {
		if (n & 1)//如果n是奇数 
			ans = (ans * m) % k;
		n = n >> 1;//位运算“右移1类似除1” 
		m = (m * m) % k;
	}
	return ans;
}

//class Matrix {
//public:
//
//	long long m[MAXN][MAXN];
//	//二维数组存放矩阵 
//	Matrix() {}
//	//对数组的初始化 
//	void init(long long  num[MAXN][MAXN]) {
//		for (int i = 0; i < MAXN; i++) {
//			for (int j = 0; j < MAXN; j++) {
//				m[i][j] = num[i][j];
//			}
//		}
//	}
//	//重载矩阵的乘法运算 
//
//	friend Matrix operator*(Matrix &m1, Matrix &m2) {
//		int i, j, k;
//		Matrix temp;
//		for (i = 0; i < MAXN; i++) {
//			for (j = 0; j < MAXN; j++) {
//				temp.m[i][j] = 0;
//				for (k = 0; k < MAXN; k++)
//					temp.m[i][j] += (m1.m[i][k] * m2.m[k][j]) % mod
//					temp.m[i][j] %= mod;
//				//注意每一步都进行取模 
//			}
//		}
//		return temp;
//	}
//	//矩阵的快速幂 
//
//	friend Matrix quickpow(Matrix &M, long long n) {
//		Matrix tempans;
//		//初始化为单位矩阵 
//		//初始化 
//		for (int i = 0; i < MAXN; i++) {
//			for (int j = 0; j < MAXN; j++) {
//				if (i == j)
//					tempans.m[i][j] = 1;
//				else
//					tempans.m[i][j] = 0;
//			}
//		}
//		//快速幂（类似整数） 
//		while (n) {
//			if (n & 1)    www.2cto.com
//				tempans = tempans * M;
//			//已经重载了* 
//			n = n >> 1;
//			M = M * M;
//		}
//		return tempans;
//	}
//};
