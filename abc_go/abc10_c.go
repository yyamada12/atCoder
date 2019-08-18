package main

import (
	"fmt"
	"math"
)

func main() {
	var txa, tya, txb, tyb, T, V, n int
	fmt.Scan(&txa, &tya, &txb, &tyb, &T, &V, &n)
	flag := false
	for i := 0; i < n; i++ {
		var x, y int
		fmt.Scan(&x, &y)
		if math.Sqrt(float64((x-txa)*(x-txa)+(y-tya)*(y-tya)))+math.Sqrt(float64((x-txb)*(x-txb)+(y-tyb)*(y-tyb))) <= float64(V*T) {
			flag = true
		}
	}
	if flag {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
