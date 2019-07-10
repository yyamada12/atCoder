package main

import (
	"fmt"
	"math"
)

func main() {
	var xa, ya, xb, yb, xc, yc int
	fmt.Scan(&xa, &ya, &xb, &yb, &xc, &yc)
	xb -= xa
	yb -= ya
	xc -= xa
	yc -= ya

	fmt.Println(math.Abs(float64(xb*yc-yb*xc)) / 2.0)

}
