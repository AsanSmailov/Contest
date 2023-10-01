import(
    "strings"
)

func isPalindrome(line string) bool{
    line=strings.ToLower(line)
    line=strings.ReplaceAll(line," ","")
    line=strings.ReplaceAll(line,"@","")
    line=strings.ReplaceAll(line,"!","")
    line=strings.ReplaceAll(line,"#","")
    line=strings.ReplaceAll(line,"~","")
    line=strings.ReplaceAll(line,"%","")
    line=strings.ReplaceAll(line,"^","")
    line=strings.ReplaceAll(line,"&","")
    line=strings.ReplaceAll(line,"*","")
    line=strings.ReplaceAll(line,"(","")
    line=strings.ReplaceAll(line,")","")
    j:=len(line)-1
    for i:=0; i<j;i++{
        if line[i]!=line[j-i]{
            return false
        }
    } 
    return true
}
