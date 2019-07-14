def find_max_subarray(a, low, high):
    # Выход из рекурсии
    if high == low:
        return low, high, a[low]
    else:
        # Разбиваем массив на 2 части
        mid = (low + high) // 2
        # Находим максимум в левой части
        left_low, left_high, left_sum = find_max_subarray(a, low, mid)
        # Находим максимум в правой части
        right_low, right_high, right_sum = find_max_subarray(a, mid + 1, high)
        # Находим кросс-максимум
        cross_low, cross_high, cross_sum = find_max_crossing_subarray(a, low, mid, high)

        if (left_sum >= right_sum) & (left_sum >= cross_sum):
            return left_low, left_high, left_sum
        elif (right_sum >= left_sum) & (right_sum >= cross_sum):
            return right_low, right_high, right_sum
        else:
            return cross_low, cross_high, cross_sum


def find_max_crossing_subarray(a, low, mid, high):
    max_left = 0
    max_right = 0

    left_sum = -1e308
    sum = 0
    # Уходим влево от центра
    for i in range(mid, low, -1):
        sum = sum + a[i]
        if sum > left_sum:
            left_sum = sum
            max_left = i
    right_sum = -1e308
    sum = 0
    # уходим вправо от центра
    for j in range(mid + 1, high):
        sum = sum + a[j]
        if sum > right_sum:
            right_sum = sum
            max_right = j

    return max_left, max_right, left_sum + right_sum

