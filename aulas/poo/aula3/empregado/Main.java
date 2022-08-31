package empregado;

import java.util.Scanner;

public class Main {
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);

		Empregado pessoa1 = new Empregado();



		pessoa1.sexo = 0;
		pessoa1.idade = 35;
		pessoa1.sb = 3500;
		pessoa1.nome = "jorgin pocas";
		System.out.println(pessoa1.calcLiquido(100, 200));
		


		System.out.println("Bondia");

	}
}