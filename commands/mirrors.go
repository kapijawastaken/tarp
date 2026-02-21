package commands

import (
	"strings"
	"os"
	"slices"
)

func slackwaremirrors() []string {
	data, err := os.ReadFile("/etc/tarp/mirrors.toml")
	if err != nil {
		panic(err)
	}

	mirrors := strings.Split(string(data), "\n")
	var slackwarearr []string
	sbopos := slices.Index(mirrors, "[SBo]")
	end := len(mirrors)

	if sbopos != -1 {
		end = sbopos
	}

	for _, line := range mirrors[:end] {
		if line != "" &&
		!strings.HasPrefix(line, "#") &&
		!strings.HasPrefix(line, "[") {
			slackwarearr = append(slackwarearr, line)
		}
	}
	if len(slackwarearr) == 0 {
		return nil
	}
	return slackwarearr
}

func sbomirrors() []string {
	data, err := os.ReadFile("/etc/tarp/mirrors.toml")
	if err != nil {
		panic(err)
	}

	mirrors := strings.Split(string(data), "\n")
	var sboarr []string
	sbopos := slices.Index(mirrors, "[SBo]")
	slackwarepos := slices.Index(mirrors, "[Packages]")
	if sbopos != -1 {
		end := len(mirrors)
		if sbopos < slackwarepos {
			end = slackwarepos
			for _, line := range mirrors[sbopos:end] {
				if line != "" &&
				!strings.HasPrefix(line, "#") &&
				!strings.HasPrefix(line, "[") {
					sboarr = append(sboarr, line)
				}
			}
		}
	}
	return sboarr
}
