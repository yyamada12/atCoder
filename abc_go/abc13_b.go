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

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	var a, b int
	fmt.Scan(&a, &b)
	d := max(a, b) - min(a, b)
	fmt.Println(min(d, 10-d))
}
