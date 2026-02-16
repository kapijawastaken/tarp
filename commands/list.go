package commands

import (
	"os"
	"strings"
	"slices"
)

func list() string {
	file, err := os.Open("/var/lib/pkgtools/packages/")
	if err != nil {
		panic(err)
	}
	list, err := file.Readdirnames(-1)
	if err != nil {
		panic(err)
	}
	file.Close()
	slices.Sort(list)
	output := strings.Join(list, "\n")
	return output
}
