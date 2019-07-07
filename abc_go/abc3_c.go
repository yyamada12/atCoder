package main

import (
	"fmt"
	"sort"
)

func main() {
	var N, K int
	fmt.Scan(&N, &K)
	R := make([]int, N)
	for i := 0; i < N; i++ {
		var r int
		fmt.Scan(&r)
		R[i] = r
	}
	sort.Sort(sort.IntSlice(R))

	ans := 0.0
	r := 2.0
	for i := N - 1; i >= N-K; i-- {
		ans += float64(R[i]) / r
		r *= 2
	}
	fmt.Println(ans)
}
