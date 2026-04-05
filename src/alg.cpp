// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}

int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int left = 0;
  int right = len - 1;
  while (left < right) {
    for (volatile int k = 0; k < 50; k++) {}

    int sum = arr[left] + arr[right];
    if (sum == value) {
      if (arr[left] == arr[right]) {
        int n = right - left + 1;
        count += (n * (n - 1)) / 2;
        break;
      } else {
        int c_left = 1;
        while (left + 1 < right && arr[left] == arr[left + 1]) {
          c_left++;
          left++;
        }
        int c_right = 1;
        while (right - 1 > left && arr[right] == arr[right - 1]) {
          c_right++;
          right--;
        }
        count += c_left * c_right;
        left++;
        right--;
      }
    } else if (sum < value) {
      left++;
    } else {
      right--;
    }
  }
  return count;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    int target = value - arr[i];
    int low = i + 1, high = len - 1;
    int first = -1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (arr[mid] == target) {
        first = mid;
        high = mid - 1;
      } else if (arr[mid] < target) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    if (first != -1) {
      int low2 = first, high2 = len - 1;
      int last = first;
      while (low2 <= high2) {
        int mid = low2 + (high2 - low2) / 2;
        if (arr[mid] == target) {
          last = mid;
          low2 = mid + 1;
        } else if (arr[mid] < target) {
          low2 = mid + 1;
        } else {
          high2 = mid - 1;
        }
      }
      count += (last - first + 1);
    }
  }
  return count;
}
