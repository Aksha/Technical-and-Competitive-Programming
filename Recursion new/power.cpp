/*
 * Complete the calculate_power function below.
 * @param a : base
 * @param b : exponent
 */
 
int calculate_power_helper(long long a, long long b, long long count, long long exponent) {
        if(count == b)
            return (int)exponent % 1000000007;
        exponent = (exponent * a) % 1000000007;
        return calculate_power_helper(a,b,count+1,exponent);
}

int calculate_power(long long a, long long b)
{
    /*
        thinking about the solution 7 mins
        coding: 8 50 pm - 8 54 pm
        debugging: 8 54 pm - 9 09 pm
    */
    if(a == 0 || a == 1 || b == 1)
        return a;
    if(b == 0)
        return 1LL;
    long long count = 0;
    long long exponent = 1;
    return calculate_power_helper(a%1000000007,b,count,exponent);
}

//Smarter SOlution which has a O(n/2) time complexity. It makes a difference as 'n' is a long long..

/*
 * Complete the calculate_power function below.
 * @param a : base
 * @param b : exponent
 */
 
/*
 * Complete the calculate_power function below.
 * @param a : base
 * @param b : exponent
 */
 
/*
 * Complete the calculate_power function below.
 * @param a : base
 * @param b : exponent
 */
 
int calculate_power_helper(long long a, long long b, long long count, long long exponent) {
        if(count == b)
            return (int)(exponent) % 1000000007;
        exponent = (exponent * a) % 1000000007;
        return calculate_power_helper(a,b,count+1,exponent);
}

int calculate_power(long long a, long long b)
{
    /*
        thinking about the solution 7 mins
        coding: 8 50 pm - 8 54 pm
        debugging: 8 54 pm - 9 09 pm
    */
    if(a == 0 || a == 1 || b == 1)
        return a;
    if(b == 0)
        return 1LL;
    long long count = 0;
    long long exponent = 1;
    long long half_exponent = calculate_power_helper(a%1000000007,b/2,count,exponent);
    int result = 0;
    if(b%2 == 1) { //if 'b' is odd
        result = (half_exponent*half_exponent*a) % 1000000007;
    }
    else { //if 'b' is even
        result = (half_exponent*half_exponent) % 1000000007;
    }
    return result;
}

//A much better solution where the time complexity is reduced to O(logn) to the base 2. How? Building along the same lines
//of the above solution. What if I reduced the problem by half every time until I get b as 0 and then calculate result everytime
//and return the "int" value to solution to the recursive function. That's a significant reduction in time complexity.

const int MOD = 1e9 + 7;

int calculate_power(long long a, long long b) {
    // base case
    if (b == 0) {
        return 1LL;
    }
    a = a % MOD;
    // recursively calculate a^(b/2)
    long long result = calculate_power(a , b/2);
    // doubling the power
    // a^(b/2) * a^(b/2) = a^b , if b is even
    result = result * result % MOD;
    // if power is odd
    if (b % 2 == 1) {
        // multiply with extra a
        result = result * a % MOD;
    }
    return(int)result;
}


