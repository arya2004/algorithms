package main
import (
	"bufio"
	"fmt"
	"math/rand"
	"os"
	"strconv"
	"time"
)

func fisherYates(a []string, rng *rand.Rand) {
	for i := len(a)-1; i > 0; i-- {
		j := rng.Intn(i+1) // 0..i
		a[i], a[j] = a[j], a[i]
	}
}

func main() {
	var arr []string
	if len(os.Args) > 1 {
		arr = os.Args[1:]
	} else {
		in := bufio.NewScanner(os.Stdin)
		for in.Scan() { arr = append(arr, in.Text()) }
	}
	seed := time.Now().UnixNano()
	if s := os.Getenv("SEED"); s != "" { if v, err := strconv.ParseInt(s, 10, 64); err == nil { seed = v } }
	rng := rand.New(rand.NewSource(seed))
	fisherYates(arr, rng)
	for i, v := range arr {
		if i>0 { fmt.Print(" ") }
		fmt.Print(v)
	}
	fmt.Println()
}
