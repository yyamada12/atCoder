package main

import (
	"fmt"
)

func main() {
	dirx := [4]int{0, 1, 0, -1}
	diry := [4]int{1, 0, -1, 0}
	var R, V, sy, sx, gy, gx int
	fmt.Scan(&R, &V, &sy, &sx, &gy, &gx)
	c := make([]string, R)
	for i := 0; i < R; i++ {
		fmt.Scan(&c[i])
	}

	type cood struct {
		x int
		y int
	}

	q := make([]cood, 0)
	used := make([][]bool, R)
	ct := make([][]int, R)
	for i := 0; i < R; i++ {
		used[i] = make([]bool, V)
		ct[i] = make([]int, V)
	}

	q = append(q, cood{sy - 1, sx - 1})
	used[sy-1][sx-1] = true

	for len(q) > 0 {
		crt := q[0]
		q = q[1:]
		for i := 0; i < 4; i++ {
			nx := crt.x + dirx[i]
			ny := crt.y + diry[i]
			if nx >= 0 && nx < R && ny >= 0 && ny < V && !used[nx][ny] && c[nx][ny] == '.' {
				used[nx][ny] = true
				q = append(q, cood{nx, ny})
				ct[nx][ny] = ct[crt.x][crt.y] + 1
			}
		}
	}
	fmt.Println(ct[gy-1][gx-1])
}
