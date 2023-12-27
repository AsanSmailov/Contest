package main

import (
	"bufio"
	"encoding/csv"
	"fmt"
	"io"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	var pclass int
	var age float64
	fmt.Scanln(&pclass, &age)
	res := map[float64][]string{}
	f, _ := os.Open("train.csv")
	r := bufio.NewReader(f)
	r.ReadString('\r')
	for {
		r_line, err := r.ReadString('\r')
		if err == io.EOF {
			break
		}
		part, _ := csv.NewReader(strings.NewReader(r_line)).Read()
		pclass1, _ := strconv.Atoi(part[2])
		age1, _ := strconv.ParseFloat(part[5], 64)
		if pclass1 == pclass && part[4] == "female" && age1 > age {
			res[age1] = append(res[age1], part[3])
		}
	}
	var keys []float64
	for k := range res {
		keys = append(keys, k)
	}
	sort.Float64s(keys)
	for _, p := range keys {
		sort.Strings(res[p])
		for _, name := range res[p] {
			fmt.Println(name)
		}
	}
}
