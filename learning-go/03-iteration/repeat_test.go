package iteration

import "testing"

func TestRepeat(t *testing.T) {
	repeated := Repeat("a")
	expected := "aaaaa"

	if repeated != expected {
		t.Errorf("expected %q but got %q", expected, repeated)
	}
}

// Benchamark
// - Caracteristica muy similar a los test en Go.
// - `*testing.B` nos da acceso a la funcion `Loop()`.
// - `Loop()`: Retorna true siempre que el punto de referencia continue ejecutandose.
// - `b.N`: Contiene el numero total de iteraciones.
// - `go test -bench=.`: Ejecutar un benchmark.
// - `ns/op`: x nanosegundos por operacion. (Depende el equipo)
// - `go test -bench=. -benchmem`: Bandera que retorna informacion sobre la asignacion de memoria.
// - `B/op`: Numero de bytes asignado por iteracion.
// - `allocs/op`: Numero de memoria asignada por iteracion
func BenchmarkRepeat(b *testing.B) {
	//... setup ...
	for b.Loop() {
		//... code to measure ...
		Repeat("a")
	}
	//... cleanup ...
}
