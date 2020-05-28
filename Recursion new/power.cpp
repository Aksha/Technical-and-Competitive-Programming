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

//Smarter SOlution which has a O(n/2) time complexity. It makes a difference as 'n' is a long long

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
    int half_product = calculate_power_helper(a%1000000007,b/2,count,exponent);
    int product = (half_product * half_product) % 1000000007;
    return product;
}

