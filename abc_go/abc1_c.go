package main

import (
	"fmt"
)

func main() {
	var Deg, Dis int
	fmt.Scan(&Deg, &Dis)
	var Dir string
	var W int
	switch {
	case Dis < 15:
		W = 0
	case Dis < 15.5*6:
		W = 1
	case Dis < 33.5*6:
		W = 2
	case Dis < 54.5*6:
		W = 3
	case Dis < 79.5*6:
		W = 4
	case Dis < 107.5*6:
		W = 5
	case Dis < 138.5*6:
		W = 6
	case Dis < 171.5*6:
		W = 7
	case Dis < 207.5*6:
		W = 8
	case Dis < 244.5*6:
		W = 9
	case Dis < 284.5*6:
		W = 10
	case Dis < 326.5*6:
		W = 11
	default:
		W = 12
	}

	switch {
	case W == 0:
		Dir = "C"
	case Deg <= 112:
		Dir = "N"
	case Deg <= 337:
		Dir = "NNE"
	case Deg <= 562:
		Dir = "NE"
	case Deg <= 787:
		Dir = "ENE"
	case Deg <= 1012:
		Dir = "E"
	case Deg <= 1237:
		Dir = "ESE"
	case Deg <= 1462:
		Dir = "SE"
	case Deg <= 1687:
		Dir = "SSE"
	case Deg <= 1912:
		Dir = "S"
	case Deg <= 2137:
		Dir = "SSW"
	case Deg <= 2362:
		Dir = "SW"
	case Deg <= 2587:
		Dir = "WSW"
	case Deg <= 2812:
		Dir = "W"
	case Deg <= 3037:
		Dir = "WNW"
	case Deg <= 3262:
		Dir = "NW"
	case Deg <= 3487:
		Dir = "NNW"
	default:
		Dir = "N"
	}

	fmt.Printf("%s %d\n", Dir, W)

}
