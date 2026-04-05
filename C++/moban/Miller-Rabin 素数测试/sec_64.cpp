typedef long long ll;

ll qpow(ll a, ll n, ll p) 
{
    ll ans = 1;
    while (n) {
        if (n & 1)
            ans = ans * a % p;
        a = a * a % p;
        n >>= 1;
    }
    return ans;
}

bool is_prime(ll x) {
    if (x < 3) 
        return x == 2;
    if (x % 2 == 0) 
        return false;
    
    ll A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    ll d = x - 1, r = 0;
    
    while (d % 2 == 0) 
        d /= 2, ++r;

    for (auto a : A) {
        if (a >= x)
            continue;
        
        ll v = qpow(a, d, x); 
        if (v <= 1 || v == x - 1) 
            continue;
        
        bool flag = false;
        for (int i = 0; i < r - 1; ++i) {
            v = v * v % x;
            if (v == x - 1) {
                flag = true;
                break;
            }
            if (v == 1)  
                return false;
        }
        if (!flag && v != 1)
            return false;
    }
    return true;
}