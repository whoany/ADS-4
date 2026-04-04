// Copyright 2021 NNTU-CS
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

        if (arr[i] > value) {
            break;
        }

        int pos = bsFirst(arr, i + 1, len - 1, target);

        if (pos == -1) {
            continue;
        }

        int left = pos;
        int right = pos;

        while (left > i + 1 && arr[left - 1] == target) {
            left--;
        }

        while (right < len - 1 && arr[right + 1] == target) {
            right++;
        }

        count += (right - left + 1);
    }

    return count;
}
