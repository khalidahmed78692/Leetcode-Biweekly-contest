class Solution
{
public:
    int uniqueXorTriplets(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 2)
            return n;
        int numberofbits = 0;
        while (n)
        {
            numberofbits++;
            n /= 2;
        }
        int ans = pow(2, numberofbits);
        return ans;
    }
};