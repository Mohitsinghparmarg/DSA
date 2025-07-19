class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        vector<int> left(nums.begin(), nums.begin() + n);
        vector<int> right(nums.begin() + n, nums.end());

        auto generateSubsetSums = [](vector<int>& arr) {
            int size = arr.size();
            unordered_map<int, vector<int>> subsets;
            for (int mask = 0; mask < (1 << size); mask++) {
                int sum = 0;
                int count = 0;
                for (int i = 0; i < size; i++) {
                    if (mask & (1 << i)) {
                        sum += arr[i];
                        count++;
                    }
                }
                subsets[count].push_back(sum);
            }
            return subsets;
        };

        auto leftSums = generateSubsetSums(left);
        auto rightSums = generateSubsetSums(right);

        for (auto& pair : rightSums) {
            sort(pair.second.begin(), pair.second.end());
        }

        int minDiff = INT_MAX;

        for (int k = 0; k <= n; k++) {
            vector<int>& leftList = leftSums[k];
            vector<int>& rightList = rightSums[n - k];

            for (int sumLeft : leftList) {
                int target = (totalSum / 2) - sumLeft;
                auto it =
                    lower_bound(rightList.begin(), rightList.end(), target);

                if (it != rightList.end()) {
                    int sumTotal = sumLeft + *it;
                    int otherHalf = totalSum - sumTotal;
                    minDiff = min(minDiff, abs(sumTotal - otherHalf));
                }

                if (it != rightList.begin()) {
                    --it;
                    int sumTotal = sumLeft + *it;
                    int otherHalf = totalSum - sumTotal;
                    minDiff = min(minDiff, abs(sumTotal - otherHalf));
                }
            }
        }

        return minDiff;
    }
};
