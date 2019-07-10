package main

import (
	"fmt"
)

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	var X, Y int
	fmt.Scan(&X, &Y)
	fmt.Println(max(X, Y))
}
