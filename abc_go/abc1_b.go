package main

import (
	"fmt"
)

func main() {
	var m float64
	fmt.Scan(&m)
	m /= 1000
	var VV int
	switch {
	case m < 0.1:
		VV = 0
	case m <= 5:
		VV = int(m * 10)
	case m <= 30:
		VV = int(m + 50)
	case m <= 70:
		VV = int((m-30)/5 + 80)
	default:
		VV = 89
	}
	fmt.Printf("%02d\n", VV)
}
