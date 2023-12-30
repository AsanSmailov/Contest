func printTypes(data []interface{}) {
    for i,_:= range data{
        if (data[i]== nil){
            fmt.Print("interface ")
        } else if data[i]== 0{
            fmt.Print("int ")
        }else if data[i]== "0"{
            fmt.Print("string ")
        }else if _, ok := data[i].(Human); ok {
            fmt.Print("Human ")
        } else if _, ok := data[i].(*Human); ok {
            fmt.Print("*Human ")
        }
        
    }
}