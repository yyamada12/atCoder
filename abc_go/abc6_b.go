package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	if n == 1 || n == 2 {
		fmt.Println(0)
		return
	}
	tri := make([]int, n)
	tri[0] = 0
	tri[1] = 0
	tri[2] = 1
	for i := 3; i < n; i++ {
		tri[i] = (tri[i-3] + tri[i-2] + tri[i-1]) % 10007
	}
	fmt.Println(tri[n-1])
}
