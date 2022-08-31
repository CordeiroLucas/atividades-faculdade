package empregado;

public class Main {
	public static void main (String[] args) {
		Empregado pessoa1 = new Empregado(902000000012345L, "jorge perera", 20, 0, 3500);

		System.out.println(pessoa1.matricula);

		System.out.printf("Matricula: %d\n", pessoa1.matricula);

		System.out.println("Bondia");

	}
}