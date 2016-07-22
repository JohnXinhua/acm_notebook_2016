ll phi(ll n) {
    ll ans = n;
    ll tmp = (ll)sqrt(n);
    FOR(i,2,tmp) if (n%i == 0) {
        while (n%i == 0) n/=i;
        ans -= ans/i;
    }
    if (n > 1) ans -= ans/n;
    return ans;
}
