package main

import (
	"fmt"
	"os"
)

func main() {
	file, err := os.Open("/var/lib/pkgtools/packages/")
	if err != nil {
		panic(err)
	}
	list, err := file.Readdirnames(-1)
	if err != nil {
		panic(err)
	}
	file.Close()
	fmt.Println(len(list))
}
