// Copyright 2021 NNTU-CS

int countPairs1(int *data, int size, int target) {
    int result = 0;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (data[i] + data[j] == target) {
                result++;
            }
        }
    }
    return result;
}

int countPairs2(int *data, int size, int target) {
    int result = 0;
    for (int i = 0; i < size - 1; i++) {
        int needed = target - data[i];
        int low = i + 1;
        int high = size - 1;
        int firstPos = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (data[mid] == needed) {
                firstPos = mid;
                high = mid - 1;
            } else if (data[mid] < needed) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        if (firstPos != -1) {
            int amount = 0;
            for (int k = firstPos; k < size && data[k] == needed; k++) {
                amount++;
            }

            if (data[i] == needed) {
                int total = 0;
                for (int k = i; k < size && data[k] == needed; k++) {
                    total++;
                }
                result += total * (total - 1) / 2;
                break;
            } else {
                result += amount;
            }
        }
    }
    return result;
}

int countPairs3(int *data, int size, int target) {
    int result = 0;
    int leftIndex = 0;
    int rightIndex = size - 1;

    while (leftIndex < rightIndex) {
        int currentSum = data[leftIndex] + data[rightIndex];

        if (currentSum == target) {
            if (data[leftIndex] == data[rightIndex]) {
                int count = rightIndex - leftIndex + 1;
                result += count * (count - 1) / 2;
                break;
            }

            int leftCount = 1;
            int rightCount = 1;

            while (leftIndex + 1 < rightIndex &&
                   data[leftIndex] == data[leftIndex + 1]) {
                leftCount++;
                leftIndex++;
            }

            while (rightIndex - 1 > leftIndex &&
                   data[rightIndex] == data[rightIndex - 1]) {
                rightCount++;
                rightIndex--;
            }

            result += leftCount * rightCount;
            leftIndex++;
            rightIndex--;
        } else if (currentSum < target) {
            leftIndex++;
        } else {
            rightIndex--;
        }
    }

    return result;
}
