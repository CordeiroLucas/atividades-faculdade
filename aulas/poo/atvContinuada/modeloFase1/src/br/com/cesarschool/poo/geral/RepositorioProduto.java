package br.com.cesarschool.poo.geral;

/**
 * @author Anônimo
 *
 * Implementação primária para efeito didático.
 * Será enormemente melhorada!!!
 */
public class RepositorioProduto {

	private static final int TAMANHO_MAX_PRODUTOS = 1000;
	
	private Produto[] cadastroProduto = new Produto[TAMANHO_MAX_PRODUTOS];
	private int tamanhoAtual = 0;
	
	public boolean incluir(Produto produto) {
		if (buscarIndice(produto.getCodigo()) != -1) {
			return false;
		} else if (tamanhoAtual == TAMANHO_MAX_PRODUTOS - 1) {
			return false;
		} else {
			for (int i = 0; i < cadastroProduto.length; i++) {
				if (cadastroProduto[i] == null) {
					cadastroProduto[i] = produto;
					break;
				}
			}
			tamanhoAtual++; 
			return true; 
		}
	}
	public boolean alterar(Produto produto) {
		int indice = buscarIndice(produto.getCodigo()); 
		if (indice == -1) {
			return false;
		} else {
			cadastroProduto[indice] = produto;
			return true; 
		}
	}
	
	public Produto buscar(long codigo) {
		int indice = buscarIndice(codigo);
		if (indice == -1) {
			return null;
		} else {
			return cadastroProduto[indice];
		}
	}
	
	public boolean excluir(long codigo) {
		int indice = buscarIndice(codigo);
		if (indice == -1) {
			return false;
		} else {
			cadastroProduto[indice] = null;
			tamanhoAtual--;
			return true;
		}		
	}
	
	private int buscarIndice(long codigo) {		
		for (int i = 0; i < cadastroProduto.length; i++) {
			Produto produto = cadastroProduto[i];
			if (produto != null && produto.getCodigo() == codigo) {
				return i; 				
			}
		}
		return -1;
	}
}
