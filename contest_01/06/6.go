package main
import (
	"fmt"
)
func main() {
    var a,b,c,d,e,f int;
    fmt.Scanf("%d", &a);
    b=a/5000;
    a=a-b*5000;
    c=a/1000;
    a=a-c*1000;
    d=a/500;
    a=a-d*500;
    e=a/200;
    a=a-e*200;
    f=a/100;
    fmt.Printf("%d %d %d %d %d", b,c,d,e,f)
}