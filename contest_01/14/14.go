package main
import "fmt"

func main() {
    var a,s,d,f,g int;
    fmt.Scanf("%d %d \n", &s, &a);
    fmt.Printf("    |");
    d=1;
    for d<=a{
         if d<10{
        fmt.Printf("   %d", d);
        } else {
           fmt.Printf("  %d", d); 
        }
        d=d+1;
    }
    fmt.Printf("\n");
    fmt.Printf("   --");
    d=1;
    for d<=a{
        fmt.Printf("----");
        d=d+1;
    }
    d=1;
    fmt.Printf("\n");
    for d<=s{
        if d<10{
        fmt.Printf("   %d|", d);
        } else {
           fmt.Printf("  %d|", d); 
        }
        f=1;
        for f<=a{
            g=d*f;
            if g<10{
            fmt.Printf("   %d", g);
            } else { 
                if g<100{
                fmt.Printf("  %d", g); 
                } else {
                fmt.Printf(" %d", g);
                }
            }
            f=f+1;
        }
        d=d+1;
        fmt.Printf("\n");
    }
    
}