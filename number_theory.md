# Number theory

## 1. GCD, LCM
GCD stands for Greatest Common Divisor (Ước chung lớn nhất) and LCM is Least Common Multiple (Bội chung nhỏ nhất).<br>
Basically we can calculate the GCD of two numbers $(a,b)$ by simple Euclidean's algorithm describes as below
```
int gcd(int a, int b) {
    if (a % b == 0) return a/b;
    return gcd(b, a%b);
}
``` 
and basic maths from middle school, $$LCM = \frac{a*b}{gcd(a,b)}$$
Another yet effective way to calculate $gcd(a,b)$ is using while loop

```
while (b != 0) {
    int remainder = a % b;
    a = b;
    b = remainder;
}
```

### 2. Prime stuff
- Sieve of Eratosthenes algorithm:
Is an effective way to count the number of primes from 1 to n.
```
void sieve_eratosthenes(int n) {
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i=2; i*i<=n; i++) {
        if (is_prime[i]) {
            for (int j=i*i; j<=n; j+=i) {
                is_prime[j] = false;
            }
        }
    }

    for (int i=1; i<=n; i++) {
        if (is_prime[i]) cout << i << " ";
    }
}
```