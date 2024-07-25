void merge(vector<int>& arr, int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;
    vector<int> left(n1);
    vector<int> right(n2);

    for (int i = 0; i < n1; ++i)
        left[i] = arr[low + i];
    for (int i = 0; i < n2; ++i)
        right[i] = arr[mid + 1 + i];

    int p1 = 0;
    int p2 = 0;
    int idx = low;
    while (p1 < n1 && p2 < n2) {
        if (left[p1] <= right[p2]) {
            arr[idx] = left[p1++];
        } else {
            arr[idx] = right[p2++];
        }
        ++idx;
    }

    while (p1 < n1)
        arr[idx++] = left[p1++];

    while (p2 < n2)
        arr[idx++] = right[p2++];
}

void merge_sort(vector<int>& arr, int low, int high) {
    if (low >= high)
        return;

    int mid = low + (high - low) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        merge_sort(nums, 0, nums.size() - 1);
        return nums;
    }
};