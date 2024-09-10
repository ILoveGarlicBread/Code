def insertion_sort(arr):
    n = len(arr)
    for i in range(1, n):
        key = arr[i]
        j = i - 1

        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j = j - 1
            print(f"sub-iteration {j}: {arr}")
        
        arr[j + 1] = key
        print(f"Iteration {i}: {arr}")

# Example usage:
arr = [12, 11, 13, 5, 6]
print("Original array:", arr)
insertion_sort(arr)
