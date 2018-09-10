#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<vector<int>> result;
    vector<int> nums;
    vector<int> temp;
    int all = 0;
    int n = 3;
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        this->nums = nums;
        this->n = nums.size();
        for (int i = 0; i < this->n + 1; i++) {
            this->all = i;
            backTrace(0, 0);
        }
        return result;
    }

private:
    void backTrace(int start, int k) {
        if (k < this->all) {
            if ((this->all - k) <= (n - start) && start < n) {
                this->temp.push_back(this->nums[start]);
                backTrace(start + 1, k + 1);
                this->temp.pop_back();
                backTrace(start + 1, k);
            } else {
                return;
            }
        } else {
            this->result.push_back(this->temp);
        }
    }
};

int main() {
    Solution s;

    std::cout << "Hello, World!" << std::endl;
    vector<int> nums = {1, 2, 3,4};
    auto result = s.subsets(nums);
    for (int i = 0; i < result.size(); i++) {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << ",";
        }
        cout << "]" << endl;
    }
    return 0;
}