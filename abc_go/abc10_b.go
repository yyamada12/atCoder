package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	ans := 0
	for i := 0; i < n; i++ {
		var a int
		fmt.Scan(&a)
		if a%2 == 0 {
			ans++
		}
		if a == 5 || a == 6 {
			ans += 2
		}
	}
	fmt.Println(ans)
}
