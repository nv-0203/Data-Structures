//calculate: x % 2^k
int mod(int num, int k)
{
    return num & ((1<<k) - 1);
}