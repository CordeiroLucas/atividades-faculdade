package classeTriangulo;

import java.util.Scanner;

// Aprendendo a usar classes e cria-las

public class AreaTriangulo {
	public static void main (String[] args) {
		Scanner ler = new Scanner(System.in);

		Triangulo triangulo = new Triangulo();

		triangulo.lado1 = ler.nextDouble();
		triangulo.lado2 = ler.nextDouble();
		triangulo.lado3 = ler.nextDouble();

		System.out.println(triangulo.areaTriangulo());
		
		ler.close();
	}
}


