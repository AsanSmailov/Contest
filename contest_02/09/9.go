import(
    "strconv"
)


func isLucky(s string) bool{
    number, _ := strconv.Atoi(s)
    a:=number/100000
    b:=(number%100000)/10000
    c:=((number%100000)%10000)/1000
    d:=(((number%100000)%10000)%1000)/100
    e:=((((number%100000)%10000)%1000)%100)/10
    f:=((((number%100000)%10000)%1000)%100)%10
    if a+b+c==d+e+f{
       return true 
    }
    return false
}