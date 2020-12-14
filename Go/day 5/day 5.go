/*
 *	Advent of Code Day 5
 *	Ethan Gingrich
 *	Learned some Go and figured (most) of this problem out on my own
 *	Had to get some help with the math for part 1 and part 2 didn't really make
 * 	sense to me so I looked up mostly how to do it
 */

package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
)

// Found on AoC subreddit cuz part 2 confused me
func contains(s []int, e int) bool {
	for _, a := range s {
		if a == e {
			return true
		}
	}
	return false
}

func main() {
	input, err := os.Open("/home/ethan/git/Advent-Of-Code-2020/Go/day 5/input.txt")
	if err != nil {
		log.Fatal(err)
	}
	defer input.Close()

	scanner := bufio.NewScanner(input)
	highest := 0
	var seatIds []int
	for scanner.Scan() {
		var lower, upper, row, left, right, col int = 0, 127, 0, 0, 7, 0
		var line string = scanner.Text()
		for i, c := range line {
			if string(c) == "F" && i == 6 {
				row = lower
			} else if string(c) == "B" && i == 6 {
				row = upper
			} else if string(c) == "F" {
				upper = ((upper - lower + 1) / 2) - 1 + lower
			} else if string(c) == "B" {
				lower = ((upper - lower + 1) / 2) + lower
			} else if string(c) == "R" && i == 9 {
				col = right
			} else if string(c) == "L" && i == 9 {
				col = left
			} else if string(c) == "R" {
				left = ((right - left + 1) / 2) + left
			} else if string(c) == "L" {
				right = ((right - left + 1) / 2) - 1 + left
			}
		}
		current := (row * 8) + col
		seatIds = append(seatIds, current) // For part 2
		// For part 1
		if current > highest {
			highest = current
		}
	}
	// For Part 2
	for j := 0; j < 128*8; j++ {
		if contains(seatIds, j+1) && contains(seatIds, j-1) && !contains(seatIds, j) {
			fmt.Println(j)
		}
	}

	if err := scanner.Err(); err != nil {
		log.Fatal(err)
	}

	fmt.Println(highest) // For Part 1
}
