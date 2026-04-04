// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value)
{
    int count = 0;

    for (int i = 0; i < len - 1; i++)
    {
        if (arr[i] > value)
            break;

        for (int j = i + 1; j < len; j++)
        {
            int sum = arr[i] + arr[j];

            if (sum == value)
                count++;
            else if (sum > value)
                break;
        }
    }
    return count;
}

int countPairs2(int* arr, int len, int value)
{
    int count = 0;
    int left = 0;
    int right = len - 1;

    while (left < right)
    {
        int sum = arr[left] + arr[right];

        if (sum < value)
        {
            left++;
        }
        else if (sum > value)
        {
            right--;
        } else {
            if (arr[left] == arr[right])
            {
                int n = right - left + 1;
                count += n * (n - 1) / 2;
                break;
            }

            int countLeft = 1;
            while (left + countLeft < right && arr[left + countLeft] == arr[left])
                countLeft++;

            int countRight = 1;
            while (right - countRight > left && arr[right - countRight] == arr[right])
                countRight++;

            count += countLeft * countRight;

            left += countLeft;
            right -= countRight;
        }
    }

    return count;
}

// Вспомогательная функция
static int binarySearchFirst(int* arr, int from, int to, int target)
{
    int result = -1;

    while (from <= to)
    {
        int mid = from + (to - from) / 2;

        if (arr[mid] == target)
        {
            result = mid;
            to = mid - 1;
        }
        else if (arr[mid] < target)
        {
            from = mid + 1;
        }
        else
        {
            to = mid - 1;
        }
    }

    return result;
}

// Вспомогательная функция
static int binarySearchLast(int* arr, int from, int to, int target)
{
    int result = -1;

    while (from <= to)
    {
        int mid = from + (to - from) / 2;

        if (arr[mid] == target)
        {
            result = mid;
            from = mid + 1;
        }
        else if (arr[mid] < target)
        {
            from = mid + 1;
        }
        else
        {
            to = mid - 1;
        }
    }

    return result;
}

int countPairs3(int* arr, int len, int value)
{
    int count = 0;

    for (int i = 0; i < len - 1; i++)
    {
        int target = value - arr[i];

        if (target < 0)
            continue;

        if (arr[i] > value)
            break;

        int first = binarySearchFirst(arr, i + 1, len - 1, target);

        if (first == -1)
            continue;

        int last = binarySearchLast(arr, i + 1, len - 1, target);

        count += (last - first + 1);
    }

    return count;
}
