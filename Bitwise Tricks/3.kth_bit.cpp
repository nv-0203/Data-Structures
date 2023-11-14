bool is_kth_bit_set(int num, int k)
{
    return (num & (1<<k));
}

void toggle_kth_bit(int num, int k)
{
    num = num ^ (1<<k);
}

void set_kth_bit(int num, int k)
{
    num = num | (1<<k);
}

void unset_kth_bit(int num, int k)
{
    num = num & ~(1<<k);
}