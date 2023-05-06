# Number theory

## 0. Combinatorics, permutation, subsets
Using bitwise brute forcing to get all the subsets of a given set
```
void getSubset(int arr[], int n) {
    for (int i = 0; i < (1 << n); i++) {
        cout << "{ ";
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                cout << arr[j] << " ";
            }
        }
        cout << "}" << endl;
    }
}
```

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
#### Sieve of Eratosthenes algorithm:
Is an effective way to count the number of primes from 1 to n.
- First we store that all numbers are primes in ``is_prime`` except 0 and 1 (which is actually not)
- For every element $i$ from 2 to $\sqrt{n}$, if $i$ is prime then we mark all the $2i, 3i, ...n$ is not prime (because it has $i$ is the divisor)
- The final array ``is_prime`` represents all the primes number (if ``is_prime[i]`` is true).
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
#### Sieve of Eratosthenes in a range from l to r
```
vector<bool> seive(r-l+1, true);
for (ll i=2; i*i <=n; i++) {
    for (ll j=max(i*i, (l-i+1)/i*i); j<=r; j+=i>)
        seive[j-l] = false;
}

if (l <= 1) seive[1-l] = false;
for (ll x=l; x<=r; x++)
    if (seive[x-l]) {
        // then x is a prime
    }


```

#### Extenxted Euclidean Algorithm
Cho 2 số A,B. GCD(A,B) luôn có thể biểu diễn dưới dạng phương trình Ax + By = GCD(A,B) 
```
int gcd, x, y;
void extendedEuclid(int A, int B) {
    if (B == 0) {
        gcd = A;
        x = 1;
        y = 0;
    } else {
        extendedEuclid(B, A%B) {
            int tmp_x = x;
            x = y;
            y = tmp_x - (A/B)*y;
        }
    }
}
```

#### Prime factor
```
vector<int> factor(int n) {
    vector<int> rs;
    for (int i=2; i*i <= n; i++) {
        while (n % i == 0) {
            rs.push_back(i);
            n /= i;
        }
    }

    if (n > 1) rs.push_back(n);
    return rs;
}
```

#### Euler's totient function
A way of calculate euler's totient function, the below is using the divisors of n method

```
ll euler_totient_2(ll n)
{
	if (n == 0) return 0;
	ll rs = n;
	for (ll x=2; x*x <= n; x++) {
		if (n%x == 0) {
			rs -= rs/x;
			while (n%x == 0) n /= x;
		}
	}

	if (n > 1) rs -= rs/n;
	return rs;
}

void solve()
{
	vector<int> m(3), x(3), y(3);
	cin >> m[0] >> m[1] >> m[2];
	cin >> x[0] >> x[1] >> x[2];
	cin >> y[0] >> y[1] >> y[2];

	ll rs = crt(m,x,y);
	LOG(rs);
}
```

### 3. Modulo and Chinese Remainder Theorem

How to calculate $a^{m}$ $mod$ $n$
``` 
ll get(ll a, ll m, ll n) {
	if (m == 0) return 1 % n;
	else if (m & 1) return a * get(a,m-1,n) % n;  
	else {
		ll fi = get(a,m/2,n);
		return (fi * fi ) % n;
	}
}
```

#### Chinese Remainder Theorem
CRT states that there's always an integer x satisfy such multi equation
$x$ $\equiv$ $a_i$ (mod $m_i$) where $m_i$ are pairwise prime (co-prime)
```
ll crt(vector<int> numbers, vector<int> remainders) {
	ll x = 1, n = numbers.size();
	while (true) {
		int j;
		for (j=0; j<n; j++)
			if (x%numbers[j] != remainders[j])
				break;

		if (j == n) return x;
		x++;
	}
	return x;
}
```
