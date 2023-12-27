type Box struct{}

func (b Box) open() Cat {
    if rand.Intn(2)==1{
        return Cat{alive: true}
    } 
    return Cat{alive: false}
}

type Cat struct {
    alive bool
}

func (c Cat) is_alive() bool {
    return c.alive
}