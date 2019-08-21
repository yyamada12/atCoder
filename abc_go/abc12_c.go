package main

import (
	"fmt"
)

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	var N int
	fmt.Scan(&N)
	n := 2025 - N
	for i := 1; i <= 9; i++ {
		if n%i == 0 && n/i <= 9 {
			fmt.Println(i, "x", n/i)
		}
	}
}
