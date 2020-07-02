package main

import "fmt"

func min(a int, b int, c int) int {
	if a <= b && a <= c {
		return a
	} else if b <= a && b <= c {
		return b
	} else {
		return c
	}
}

func minDistance(word1 string, word2 string) int {

	var e [][]int
	for i := 0; i <= len(word1); i++ {
		row := make([]int, len(word2)+1)
		row[0] = i
		e = append(e, row)
	}
	for i := 1; i <= len(word2); i++ {
		e[0][i] = i
	}
	for i := 1; i <= len(word1); i++ {
		for j := 1; j <= len(word2); j++ {
			a := e[i][j-1] + 1
			b := e[i-1][j-1]
			c := e[i-1][j] + 1
			if word1[i-1] != word2[j-1] {
				b += 1
			}
			e[i][j] = min(a, b, c)
		}
	}
	return e[len(word1)][len(word2)]
}

func main() {
	fmt.Println(minDistance("horse", "ros"))
}
