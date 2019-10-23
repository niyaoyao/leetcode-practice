package main

import (
  "fmt"
  "unsafe"
)

const testString = "Calculator Demo"

func main() {
	fmt.Println("Hello world")
	selectMenu()
}

func selectMenu() {
	fmt.Println("\n=================")
	fmt.Println("Select Function Index:")
	fmt.Println("0. Exit")
	fmt.Println("1. Basic Syntax")
	fmt.Println("2.", testString)
	fmt.Println("3. Palindrome String")
	fmt.Println("4. Fibonacci Number")
	fmt.Println("5. Greatest Common Divisor")
	fmt.Println("=================\n")
	var index int = -1
	fmt.Scanln(&index)
	// Function Array & Call Function By Index
	switch index {
	case 0: 
		fmt.Println("See you ~")
		return;
	case 1:
		syntaxPractice()
	case 2:
		calculatorDemo()
	case 3:
		palindromeString()
	case 4:
		fibonacciNumberDemo()
	case 5:
		greatestCommonDivisorDemo()
	default:
		fmt.Println("===== Not Found Selected Index =====\n")
	}
	selectMenu()
}

func calculatorDemo() {
	fmt.Println("Welcome:", testString)
	var a float64
	var b float64
	
	fmt.Println("Input a number:")
	fmt.Scanln(&a)
	fmt.Println("a:", a)

	fmt.Println("Input second number:")
	fmt.Scanln(&b)
	fmt.Println("b:", b)

	fmt.Println("a + b = ", a + b)
	fmt.Println("a - b = ", a - b)
	fmt.Println("a * b = ", a * b)
	fmt.Println("a / b = ", a / b)
}

func palindromeString() {
	fmt.Println("Welcome: Palindrome String")
}

func fibonacciNumberDemo() {
	fmt.Println("Welcome Fibonacci Number")
	fmt.Println("Input a integer number")

	var number int
	fmt.Scanln(&number)
	var result = fibonacciNumber(number)
	fmt.Println("The Fibonacci Number of", number, "is", result)
}

func fibonacciNumber(number int) int {
	if number == 0 {
		return 0
	} else {
		if number == 1 {
			return 1
		} else {
			return fibonacciNumber(number - 1) + fibonacciNumber(number - 2)
		}
	}
}

func syntaxPractice() {
	fmt.Println("Welcome to Basic Syntax Practice")
	var str string
	fmt.Println("Default value of 'var str string' :", str)

	var i, j, k int
	fmt.Println("Default value of 'var i int' :", i)
	fmt.Println("Default value of 'var j int' :", j)
	fmt.Println("Default value of 'var k0 int' :", k)

	var number float64
	fmt.Println("Default value of 'var number int' :", number)

	x := 666
	p := &x

	fmt.Println("&x", p)
	
	*p += 777

	fmt.Println("*p += 777", x)

	q := unsafe.Pointer(&x)
	size := unsafe.Sizeof(x)
	fmt.Println("q:", q, "\tsize:", size)
	offset2Pointer := unsafe.Pointer(uintptr(q) + size)
	fmt.Println("offset2Pointer:", offset2Pointer)


	x += 1
	fmt.Println("*p:", *p)
}

func greatestCommonDivisorDemo() {
	fmt.Println("Input a integer number:")
	var a int
	fmt.Scanln(&a)
	fmt.Println("Input another integer number:")
	var b int
	fmt.Scanln(&b)
	result := greatestCommonDivisor(a, b)
	fmt.Println("The Greatest Common Divisor of ", a, "and", b, "is", result)
}

func greatestCommonDivisor(x, y int) int {
    for y != 0 {
        x, y = y, x%y
    }
    return x
}
// func twoSum(nums []int, target int) []int {
// 	return [0, 1]
// }