package main

import (
	"fmt"
	"io/ioutil"
	"os"
)

func printer(file string) error {
	fi, err := os.Stat(file)
	if err != nil {
		return err
	}

	if fi.Mode().IsRegular() {
		fmt.Println(file)
	} else if fi.Mode().IsDir() {
		files, err := ioutil.ReadDir(file)
		if err != nil {
			return err
		}
		for _, f := range files {
			printer(f.Name())
		}
	}

	return nil
}

func main() {
	if err := printer("."); err != nil {
		fmt.Println(err.Error())
	}

	return
}
