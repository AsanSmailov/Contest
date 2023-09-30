package main

import "fmt"
    


func main() {
    var n,i int;
    var a float64;

    fmt.Scanln(&n);

    d := make([]float64, n);
    for i = 0; i < n; i++ {
        fmt.Scan(&d[i]);
    }

    for i = 0; i < n; i++ {
        if i == 0 || i == n-1 {  
            fmt.Printf("%.1f ", d[i]);
            continue
        }
        a = (d[i-1] + d[i] + d[i+1]) / 3 ;        
        fmt.Printf("%.15f ", a);
 }
}