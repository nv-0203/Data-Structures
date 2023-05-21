int maxpathsum(Node *root)
{
    int sum = INT_MIN;
    maxpathdown(root, sum);
    return sum;
}