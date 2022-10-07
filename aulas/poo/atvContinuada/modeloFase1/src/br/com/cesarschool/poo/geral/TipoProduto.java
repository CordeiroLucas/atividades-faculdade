package br.com.cesarschool.poo.geral;

/**
 * Pesquisar sobre "enum" em Java, ler sobre e se inteirar do assunto
 * para criar um enum TipoCorrentista na atividade continuada
 */
public enum TipoProduto {
	ALIMENTO(1, "Alimento"), 
	LIMPEZA(2, "Limpeza"), 
	ELETRO(3,"Eletro"); 
	
	private int codigo;
	private String descricao;
	
	private TipoProduto(int codigo, String descricao) {
		this.codigo = codigo;
		this.descricao = descricao;
	}

	public int getCodigo() {
		return codigo;
	}

	public String getDescricao() {
		return descricao;
	}

	
	public static TipoProduto obterPorCodigo(int codigo) {
		for (TipoProduto tipoProduto : TipoProduto.values()) {
			if (tipoProduto.getCodigo() == codigo) {
				return tipoProduto;
			}
		}
		return null;
	}
}
