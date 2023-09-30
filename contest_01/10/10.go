package main
import (
	"fmt"
)
func main() {
    var l,z,x string;
    fmt.Scanf("%s %s %s /n",&l,&z,&x);
    if l=="Нет" {
        if z=="Нет"{
            if x=="Нет"{
             fmt.Println("Кот")   
            }else{
              fmt.Printf("Жираф")  
            }
        } else{
            if x=="Нет"{
             fmt.Println("Курица")   
            }else{
              fmt.Printf("Страус")  
            }
        }
        
    } else{
        if z=="Нет"{
            if x=="Нет"{
             fmt.Println("Дельфин")   
            }else{
              fmt.Printf("Плезиозавры")  
            }
        } else{
            if x=="Нет"{
             fmt.Println("Пингвин")   
            }else{
              fmt.Printf("Утка")  
            }
        }
    }

}
