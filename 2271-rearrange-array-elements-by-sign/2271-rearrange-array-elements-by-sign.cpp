class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        int n = nums.size();
        vector<int> v(n, 0);
        int OddIndex = 0;
        int EvenIndex = 1;
        for (auto it : nums) {

            if (it > 0) {
                v[OddIndex] = it;
                OddIndex += 2;
            } else {
                v[EvenIndex] = it;
                EvenIndex += 2;
            }
        }
        return v;
    }
};