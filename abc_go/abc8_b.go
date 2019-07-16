package main

import (
	"fmt"
)

func main() {
	var N int
	fmt.Scan(&N)
	mp := make(map[string]int)
	for i := 0; i < N; i++ {
		var s string
		fmt.Scan(&s)
		mp[s]++
	}
	max := 0
	ans := ""
	for k, v := range mp {
		if v > max {
			max = v
			ans = k
		}
	}
	fmt.Println(ans)
}
