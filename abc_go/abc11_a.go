package main

import (
	"fmt"
)

func main() {
	var N int
	fmt.Scan(&N)
	if N == 12 {
		fmt.Println(1)
	} else {
		fmt.Println(N + 1)
	}
}
