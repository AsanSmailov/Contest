package main
import (
    "fmt"
    "sort"
    )


func main() {
    var n,x int;
    fmt.Scanln(&n, &x)
    num:=make ([] int,n)
    for i:=0;i<n;i++{
        fmt.Scan(&num[i])
    }
    sort.Ints(num)
    left:=0
    right:=n-1
    for left<right{
        sum:= num[left]+num[right]
        if sum==x{
            fmt.Print(num[left],num[right])
            break
        }else if sum<x{
            left++
        }else {
            right--
        } 
    }
    if left==right{
        fmt.Print("0 ","0")
    }
}