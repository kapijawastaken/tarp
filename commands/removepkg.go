package commands

import "os/exec"

func removepkg(args []string) string {
	switch len(args) {
	default:
		cmd := exec.Command("removepkg ", args...)
		output, err := cmd.Output()
		if err != nil {
			panic(err)
		}
		return string(output)
	case 0:
		return help()
	case 1:
		cmd := exec.Command("removepkg ", args...)
		output, err := cmd.Output()
		if err != nil {
			panic(err)
		}
		return string(output)
	}
}
