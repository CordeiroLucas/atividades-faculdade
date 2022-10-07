package br.com.cesarschool.poo.geral;

import javax.swing.event.SwingPropertyChangeSupport;

/**
 * @author An�nimo
 *
 * Implementa��o prim�ria para efeito did�tico.
 * Ser� enormemente melhorada!!!
 */
public class Produto {
	public static final int SUCESSO = 0;
	public static final int NOME_NAO_INFORMADO = 1; 
	public static final int NOME_MUITO_CURTO = 2; 
	public static final int TAMANHO_MINIMO_NOME = 3;


	private long codigo;
	private String nome;
	private double preco;
	private TipoProduto tipo;
	
	public Produto(long codigo, String nome, double preco, TipoProduto tipo) {
		this.codigo = codigo;
		this.nome = nome;
		this.preco = preco;
		this.tipo = tipo;
	}
	
	public long getCodigo() {
		return codigo;
	}
	public void setCodigo(long codigo) {
		this.codigo = codigo;
	}
	public String getNome() {
		return nome;
	}
	public void setNome(String nome) {
		this.nome = nome;
	}
	public double getPreco() {
		return preco;
	}
	public void setPreco(double preco) {
		this.preco = preco;
	}
	public TipoProduto getTipo() {
		return tipo;
	}
	public void setTipo(TipoProduto tipo) {
		this.tipo = tipo;
	}

	/**
	 * O conceito de c�digo v�lido � codigo > 0
	 * 
	 * @return true se o c�digo for v�lido e false caso contr�rio.
	 */
	boolean codigoValido() {
		if (this.codigo <= 0) {
			return false;
		}
		return true;
	}
	/**
	 * M�todo respons�vel por valida o atributo nome
	 * 
	 * O nome � obrigat�rio. 
	 * 
	 * @return Caso o nome n�o esteja preenchido, retorna NOME_NAO_INFORMADO.
	 *         Caso o nome tenha menos do que TAMANHO_MINIMO_NOME caracteres,
	 *         retorna NOME_MUITO_CURTO. Caso contr�rio, retorna SUCESSO. 
	 */
	int validarNome() {
		if (nome == null || nome.trim().equals("")) {
			return NOME_NAO_INFORMADO;
		} else if (nome.trim().length() < TAMANHO_MINIMO_NOME) {
			return NOME_MUITO_CURTO;
		}
		return SUCESSO;
	}
	boolean precoValido() {
		return this.preco > 0;
	}
	boolean tipoPreechido() {
		return tipo != null;
	}
}
