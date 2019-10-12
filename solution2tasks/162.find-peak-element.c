int findPeakElement(int* nums, int numsSize) {
    int left = 0;
    int right = numsSize - 1;
    int mid = right / 2;
    while (left < right) {
        if (nums[mid] > nums[mid + 1]) {
            right = mid;
        } else {
            left = mid + 1;
        }
        mid = (left + right) / 2;
    }
    return left;
}
