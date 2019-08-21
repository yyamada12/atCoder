package main

import (
	"fmt"
)

func main() {
	var N int
	fmt.Scan(&N)
	fmt.Printf("%02d:%02d:%02d\n", N/60/60, N/60%60, N%60)
}
