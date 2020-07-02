package main

import "fmt"

func min(a int, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

func calculateMinimumHP(dungeon [][]int) int {
	size_c := len(dungeon)
	size_r := len(dungeon[0])
	health_min := make([]int, size_c)
	health_min[size_c-1] = max(-dungeon[size_c-1][size_r-1]+1, 1)
	for i := size_c - 2; i >= 0; i-- {
		health_min[i] = max(health_min[i+1]-dungeon[i][size_r-1], 1)
	}
	for j := size_r - 2; j >= 0; j-- {
		fmt.Println(health_min)
		health_min[size_c-1] = max(health_min[size_c-1]-dungeon[size_c-1][j], 1)
		for i := size_c - 2; i >= 0; i-- {
			h1 := min(health_min[i], health_min[i+1]) - dungeon[i][j]
			health_min[i] = max(h1, 1)
		}
	}
	fmt.Println(health_min)
	return health_min[0]
}

func main() {
	a := [][]int{{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}}
	fmt.Println(calculateMinimumHP(a))
}
