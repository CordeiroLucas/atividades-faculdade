package classeTriangulo;

//criação da classe Triangulo

public class Triangulo {
	double lado1;
	double lado2;
	double lado3;
	double semiPerimetro() {
		return (lado1+lado2+lado3)/2;
	}
	double areaTriangulo() {
		return Math.sqrt((semiPerimetro()*(semiPerimetro() - lado1)*(semiPerimetro() - lado2)*(semiPerimetro() - lado3)));
	}
}