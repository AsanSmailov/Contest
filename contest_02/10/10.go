func shift(arr []int, steps int) {
    n := len(arr)
    steps %= n
    if steps < 0 {
        steps = n + steps
    }
    newArr := make([]int, n)
    for i := 0; i < n; i++ {
        newIndex := (i + steps) % n
        newArr[newIndex] = arr[i]
    }
    copy(arr, newArr)
}