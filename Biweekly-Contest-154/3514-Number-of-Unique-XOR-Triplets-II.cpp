class Solution
{
public:
    int uniqueXorTriplets(vector<int> &nums)
    {
        unordered_set<int> one, two, three;
        for (int num : nums)
        { // O(n)
            one.insert(num);
            for (int x : one)
            { // O(2048)
                two.insert(x ^ num);
            }
            for (int x : two)
            { // O(2048)
                three.insert(x ^ num);
            }
        }
        return three.size();
    }
};