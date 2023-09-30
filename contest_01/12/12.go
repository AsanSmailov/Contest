package main
import "fmt"


func main() {
    var x,a int;
    fmt.Scanln(&x);
    for x>1{
    if x%2==0 {
        x=x/2;
        a=a+1;
    } else {
        x= 3*x+1;
        a=a+1;
    }
    }
    fmt.Println(a)
}
