package aulas.poo.aula4.encapsulamento;

class Loja
{
	String nome;
	private long cep;
	double receita;
	void mudaCep(long newCep)
	{
		cep = newCep;
	}
	void adicionaReceita(double valor)
	{
		receita += valor;
	}
	public void printCep()
	{
		System.out.printf("CEP: %d\n", cep);
	}
}

class encapsulamento {
	public static void main(String[] args)
	{
		Loja loja1 = new Loja();
		loja1.nome = "Bondia";
		loja1.mudaCep(123456789123456L);
		loja1.printCep();

		Loja loja2 = new Loja();
		loja2.nome = loja1.nome;
		loja1.nome = "jorge";
		System.out.println(loja2.nome);
		System.out.println(loja1.nome);
	}
}
