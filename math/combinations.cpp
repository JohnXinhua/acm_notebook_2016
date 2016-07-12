/**********************************
    Tính t? h?p C(n, k) % mod

**********************************/

const int MN = 1000006;
const int mod = 1000003;

long long x, y, fact[MN+10];

void init() {
   fact[0] = 1;
   FOR(i,1,MN) fact[i] = (fact[i-1]*i) % mod;
}

void extenedEuclid(long long a, long long b) {
   if (b == 0) {
      x = a;
      y = 0;
      return;
   }
   extenedEuclid(b, a % b);
   long long tmp = y;
   y = x - a/b*y;
   x = tmp;
}

long long comb(long long n, long long k) {
   if (n < k) return 0;
   long long tmp = (fact[k]*fact[n-k]) % mod;
   extenedEuclid(tmp, mod);
   tmp = x;
   while (tmp < 0) tmp += mod;
   tmp %= mod;
   return fact[n]*tmp % mod;
}

