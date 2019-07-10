package main

import (
	"fmt"
	"strings"
)

func main() {
	var W string
	fmt.Scan(&W)
	w1 := strings.Replace(W, "a", "", -1)
	w2 := strings.Replace(w1, "i", "", -1)
	w3 := strings.Replace(w2, "u", "", -1)
	w4 := strings.Replace(w3, "e", "", -1)
	w5 := strings.Replace(w4, "o", "", -1)
	fmt.Println(w5)
}
