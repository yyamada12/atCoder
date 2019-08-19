package main

import (
	"fmt"
	"sort"
)

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	var N int
	var NG [3]int
	fmt.Scan(&N, &NG[0], &NG[1], &NG[2])
	sort.Ints(NG[:])
	if N == NG[2] {
		fmt.Println("NO")
		return
	}

	dp := make([]int, N+1)
	for i := 0; i <= N; i++ {
		dp[i] = 10000
	}
	dp[N] = 0
	for i := N; i >= 0; i-- {
		if i == NG[0] || i == NG[1] || i == NG[2] {
			continue
		}
		for j := 1; j <= 3; j++ {
			if i-j >= 0 {
				dp[i-j] = min(dp[i]+1, dp[i-j])
			}
		}
	}
	if dp[0] <= 100 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
