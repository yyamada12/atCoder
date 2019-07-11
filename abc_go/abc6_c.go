package main

import (
	"fmt"
)

func main() {
	var N, M int
	fmt.Scan(&N, &M)

	if M < 2*N || M > 4*N {
		fmt.Println("-1 -1 -1")
	} else if M <= 3*N {
		n3 := M - 2*N
		fmt.Printf("%d %d %d\n", N-n3, n3, 0)
	} else if M <= 4*N {
		n4 := M - 3*N
		fmt.Printf("%d %d %d\n", 0, N-n4, n4)
	}

}
