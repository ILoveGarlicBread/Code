def merge_sort(arr):
    print("Splitting:", arr)
    if len(arr) <= 1:
        return arr
    
    # Divide the array into two halves
    mid = len(arr) // 2
    left_half = arr[:mid]
    right_half = arr[mid:]
    
    # Recursively sort each half
    left_half = merge_sort(left_half)
    right_half = merge_sort(right_half)
    
    # Merge the sorted halves
    return merge(left_half, right_half)

def merge(left, right):
    print("Merging:", left, right)
    merged = []
    left_index, right_index = 0, 0
    
    # Compare elements from both lists and add the smaller one to the merged list
    while left_index < len(left) and right_index < len(right):
        if left[left_index] < right[right_index]:
            merged.append(left[left_index])
            left_index += 1
        else:
            merged.append(right[right_index])
            right_index += 1
    
    # Add any remaining elements from the left and right lists
    merged.extend(left[left_index:])
    merged.extend(right[right_index:])
    
    print("Merged:", merged)
    return merged

# Example usage:
arr = [3, 1, 4, 1, 5, 9, 2, 6]
sorted_arr = merge_sort(arr)
print("Sorted array:", sorted_arr)

