package main
import (
	"fmt"
)
func main() {
    var a,b,c int;
    fmt.Scanf("%d %d %d", &a,&b,&c);
    if a>b {
        if a>c{
        fmt.Printf("%d",a)
    } else {
        fmt.Printf("%d",c)
    } 
    }else if b>c {
        fmt.Printf("%d",b)
    } else {
        fmt.Printf("%d",c)
    }
    

}