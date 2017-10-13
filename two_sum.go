package main

import "fmt"

func main() {
	numbers := []int{1, 4, 6, 7, 2, 3, 6, 5, 2}
	target := 13

	// Create the map for lookup purposes.
	lookup := make(map[int]int, len(numbers))
	for _, i := range numbers {
		if _, ok := lookup[i]; !ok {
			lookup[i] = 1
		} else {
			lookup[i]++
		}
	}

	// Check for a sum to target.
	for _, v := range numbers {
		required := target - v
		if w, ok := lookup[required]; ok {
			// Special case, don't use self.
			if required == v {
				if w == 1 {
					continue
				}
			}
			fmt.Printf("Found %d and %d which sum to %d\n", v, required, target)
		}
	}
}
