typedef long long ll;

// 快速幂：a^n mod p，处理64位溢出
ll qpow(ll a, ll n, ll p) 
{
    ll ans = 1;
    while (n)
    {
        if (n & 1)
            ans = (__int128)ans * a % p; // __int128过渡避免溢出
        a = (__int128)a * a % p;
        n >>= 1;
    }
    return ans;
}

bool is_prime(ll x)
{
    // 特判：x<3时，只有2是素数
    if (x < 3) 
        return x == 2;
    // 特判偶数
    if (x % 2 == 0) 
        return false;
    
    // 确定性基集合（覆盖2^64以内所有数）
    ll A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    ll d = x - 1, r = 0;
    
    // 分解x-1 = d * 2^r（d为奇数）
    while (d % 2 == 0) 
        d /= 2, ++r;
    // 优化写法（GCC内置函数，更快）：
    // r = __builtin_ctzll(x - 1); // 注意用__builtin_ctzll处理long long
    // d = (x - 1) >> r;

    // 遍历所有基
    for (auto a : A)
    {
        // 【修改1】跳过大于等于x的基，避免无意义计算
        if (a >= x)
            continue;
        
        ll v = qpow(a, d, x); // 计算a^d mod x
        // 若v<=1（v=0或1）或v=x-1（-1），直接通过当前基测试
        if (v <= 1 || v == x - 1) 
            continue;
        
        // 【修改2】循环次数从r次改为r-1次（数学上只需平方r-1次）
        bool flag = false; // 标记是否找到-1
        for (int i = 0; i < r - 1; ++i)
        {
            v = (__int128)v * v % x; // 模平方
            // 【修改3】去掉i != r-1的冗余判断
            if (v == x - 1) 
            {
                flag = true;
                break;
            }
            // 找到非平凡平方根（平方=1但自身≠±1），直接判定合数
            if (v == 1)  
                return false;
        }
        // 若没找到-1，或最终v≠1，判定合数
        if (!flag && v != 1)
            return false;
    }
    return true;
}