package main

import "fmt"

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

func partition(heights []int, p int, q int) int {
	min := heights[p]
	min_p := p
	for i := p + 1; i <= q; i++ {
		if min > heights[i] {
			min = heights[i]
			min_p = i
		}
	}
	return min_p

}

func largestRectangleArea(heights []int) int {
	return linarlra(heights)

}
func linarlra(heights []int) int {
	if len(heights) == 0 {
		return 0
	}
	m := heights[0]
	pre := heights[0]
	for i := 1; i < len(heights); i++ {
		var cur int
		v := heights[i]
		if heights[i-1] > v {
			cur = pre/heights[i-1]*v + v
		} else {
			cur = max(pre+heights[i-1], v)
		}
		fmt.Println(cur)
		if m < cur {
			m = cur
		}
		pre = cur
	}
	return m
}

func lra(heights []int, p int, q int) int {
	if p > q {
		return 0
	}
	r := partition(heights, p, q)
	a := lra(heights, p, r-1)
	b := lra(heights, r+1, q)
	c := (q - p + 1) * heights[r]
	fmt.Println(a, b, c)
	return max(a, max(b, c))

}

func main() {
	a := []int{1, 2, 3, 4, 5}
	fmt.Println(largestRectangleArea(a))
}
