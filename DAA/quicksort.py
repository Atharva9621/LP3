def swap(arr: list[int], i: int, j: int) -> None:
    temp = arr[i]
    arr[i] = arr[j]
    arr[j] = temp

def partition(arr: list[int], l: int, r: int) -> int:
    pivot = arr[r]
    i = l - 1
    for j in range(l, r):
        if arr[j] < pivot:
            i += 1
            swap(arr, i, j)
    swap(arr, i + 1, r)
    return i + 1

def quicksort(arr: list[int], i: int = 0, j: int = None) -> None:
    if j is None:
        j = len(arr) - 1

    if i < j:  
        pivot = partition(arr, i, j)
        quicksort(arr, i, pivot - 1)
        quicksort(arr, pivot + 1, j)

if __name__ == "__main__":
    arr = [1, 4, 2, 3, 2, 1, 7, 5, 8, 2, 6, 1]
    print("Before sorting:", arr)
    quicksort(arr)
    print("After sorting:", arr)