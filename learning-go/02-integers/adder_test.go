package integers

import (
	"fmt"
	"testing"
)

func TestAdder(t *testing.T) {
	sum := Add(2, 2)
	expected := 4

	if sum != expected {
		// %d -> formatear 'int' dentro de un string.
		t.Errorf("expected '%d' but got '%d'", expected, sum)
	}
}

// Testable Examples
// - Las 'Example Functions' son compiladas cuando los test son ejecutados.
// - Inician con 'Example**'.
// - Residen dentro del paquete '_test.go'.
// - El comentario que inica con '// Output: **' hace que el ejemplo tambien se ejecute.
func ExampleAdd() {
	sum := Add(1, 5)
	fmt.Println(sum)
	// Output: 6
}
