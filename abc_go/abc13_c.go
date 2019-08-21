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
	var N, H, A, B, C, D, E int
	fmt.Scan(&N, &H, &A, &B, &C, &D, &E)
	ans := 1000000000000
	H = N*E - H
	for n := 0; n <= N; n++ {
		if n*(B+E) > H {
			ans = min(ans, n*A)
		} else {
			ans = min(ans, n*A+((H-n*(B+E))/(D+E)+1)*C)
		}
	}
	fmt.Println(ans)
}
