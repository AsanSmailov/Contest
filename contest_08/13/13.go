type SimpleStack struct {
    data []rune
}

func NewSimpleStack() *SimpleStack {
    return &SimpleStack{}
}

func (s *SimpleStack) empty() bool{
    if len(s.data)==0{
        return true
    }
    return false
}
func (s *SimpleStack) push(r rune) {
    s.data = append(s.data, r)
}

func (s *SimpleStack) top() rune{
    return s.data[len(s.data)-1]
}
func (s *SimpleStack) pop() rune{
    index := len(s.data) - 1
    value := s.data[index]
    s.data = s.data[:index]
    return value
}