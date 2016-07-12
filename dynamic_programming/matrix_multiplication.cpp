
/**********************************

          Matrix template
          
***********************************/

struct matrix {
   long long x[100][100];
   int n, m;
   
   matrix (int n = 0, int m = 0) : n(n), m(m) {
      FOR(i,1,n) FOR(j,1,m) x[i][j] = 0LL;
   }
   void print() {
      FOR(i,1,n) {
         FOR(j,1,m) cout << x[i][j] << " ";
         cout << endl;
      }
   }
};

matrix operator * (const matrix &a, const matrix &b) {
   matrix c(a.n, b.m);
   FOR(i,1,c.n) FOR(j,1,c.m) {
      FOR(k,1,a.m)
         c.x[i][j] = (c.x[i][j] + a.x[i][k]*b.x[k][j]) % mod;
   }
   return c;
}

matrix _pow(matrix a, long long n) {
   if (n == 1) return a;
   matrix tmp = _pow(a, n/2);
   if (n & 1) return tmp * tmp * a;
   return tmp * tmp;
}

matrix identity(int n) {
   matrix res(n, n);
   FOR(i,1,n) res.x[i][i] = 1LL;
   return res;
}
