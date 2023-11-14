bool powerof2(int x)
{
    return x && !(x & (x-1));
}

/*
x && !(x & (x-1))

first x in the && equation is to make sure it returns false for 0
if (x & (x-1)) == 0: it is power of 2

eg. x :       0000100000000
    x-1:      0000011111111
    x & x-1 : 0000000000000
*/