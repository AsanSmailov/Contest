package main
import "fmt"


func Contains(num []int, x int) int {
    a:=0
    s:=0
    for _, n := range num {
        if x == n {
            a=a+1
        }
        s=a%2
    }
    if s!=0 {
       return x
    }
    
    return 0
}
func main() {
    var n int;
    fmt.Scanln(&n)
    num:=make ([] int,n)
    for i:=0;i<n;i++{
        fmt.Scan(&num[i])
    }
    res:=0
    for i:=0;i<n;i++{
        res=Contains(num [:], num[i])
        if res!=0{
           fmt.Println(res) 
           break
        }
    }
    
}