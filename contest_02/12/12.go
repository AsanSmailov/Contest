func countMines(row, col int, arr [][]int) int {
    count := 0
    for i := row - 1; i <= row+1; i++ {
        for j := col - 1; j <= col+1; j++ {
            if i >= 0 && i < len(arr) && j >= 0 && j < len(arr[0]) && arr[i][j] == -1 {
                count++
            }
        }
    }
    return count
}

func fill(arr [][]int) {
    for i := 0; i < len(arr); i++ {
        for j := 0; j < len(arr[0]); j++ {
            if arr[i][j] != -1 {
                arr[i][j] = countMines(i, j, arr)
            }
        }
    }
}