package main
import (
	"fmt"
	"math"
)
func main() {
    var a,b,c float64;
    a=0.5*365;
    b=a/32;
    c=a/20;
    fmt.Printf("%.1f %.0f %.0f",a,math.Ceil(b),math.Ceil(c));
}
