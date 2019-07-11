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
	ans := 100
	for i := 0; i < N; i++ {
		var t int
		fmt.Scan(&t)
		ans = min(ans, t)
	}
	fmt.Println(ans)
}
