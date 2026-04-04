// Copyright 2025 Vadim
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
    int count = 0;

    for (int left = 0; left < len - 1; left++) {
        if (arr[left] > value) {
            break;
        }

        int right = len - 1;

        while (right > left &&
               arr[left] + arr[right] > value) {
            right--;
        }

        for (int j = right; j > left; j--) {
            if (arr[left] + arr[j] == value) {
                count++;
            }
        }
    }

    return count;
}

static int bsFirst(int *arr, int from,
                    int to, int target) {
    int result = -1;
    while (from <= to) {
        int mid = from + (to - from) / 2;
        if (arr[mid] == target) {
            result = mid;
            to = mid - 1;
        } else if (arr[mid] < target) {
            from = mid + 1;
        } else {
            to = mid - 1;
        }
    }
    return result;
}

static int bsLast(int *arr, int from,
                   int to, int target) {
    int result = -1;
    while (from <= to) {
        int mid = from + (to - from) / 2;
        if (arr[mid] == target) {
            result = mid;
            from = mid + 1;
        } else if (arr[mid] < target) {
            from = mid + 1;
        } else {
            to = mid - 1;
        }
    }
    return result;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        int target = value - arr[i];
        if (target < 0) {
            continue;
        }
        if (arr[i] > value) {
            break;
        }
        int first = bsFirst(arr, i + 1,
                             len - 1, target);
        if (first == -1) {
            continue;
        }
        int last = bsLast(arr, i + 1,
                           len - 1, target);
        count += (last - first + 1);
    }
    return count;
}
