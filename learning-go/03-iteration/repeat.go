package iteration

import "strings"

const repeatCount = 5

func Repeat(character string) string {
	// String
	// - strings.Builder: Es un tipo que permite minimizar la memoria al copiar un string.
	// - WriteString(): Metodo para concatenar strings.
	// - .String(): Retorna un tipo string.
	// - PD: Debemos importar "strings" para usar estos metodos.
	var repeated strings.Builder
	for i := 0; i < repeatCount; i++ {
		repeated.WriteString(character)
	}
	return repeated.String()
}
