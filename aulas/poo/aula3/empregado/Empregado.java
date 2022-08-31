package empregado;

public class Empregado {
	long matricula;
	String nome;
	int idade;
	int sexo;
	double sb;
	boolean isIdoso() {
		if (idade >= 60) return true;
		else return false;
	}
	double calcLiquido(double ap, double air) {
		if (isIdoso()) return (1 - ap/100 - (0.8*air) * 100) * sb;  //Retorna o salario liquido se idoso = true
		else return (1 - ap/100 - air/100) * sb;  //Retorna o salario liquido se idoso = false
	}
	Empregado (long matricula, String nome, int idade, int sexo, double sb) {
		this.matricula = matricula;
		this.nome = nome;
		this.idade = idade;
		this.sexo = sexo;
		this.sb = sb;
	}
}