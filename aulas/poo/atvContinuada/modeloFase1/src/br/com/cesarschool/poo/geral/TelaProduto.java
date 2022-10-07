package br.com.cesarschool.poo.geral;

import java.util.Scanner;

/**
 * @author Anônimo
 *
 * Trata-se de uma implementação de tela primária, para efeito didático e de demonstração simplificada
 * da arquitetura em camadas e do custo de implementação de uma interface visual, por mais simples que
 * seja!
 * 
 */
public class TelaProduto {
	
	private static final int CODIGO_DESCONHECIDO = -1;
	private static final Scanner ENTRADA = new Scanner(System.in);
	private RepositorioProduto repositorioProduto = new RepositorioProduto();
	
	public void executaTela() {
		while(true) {
			long codigo = CODIGO_DESCONHECIDO;
			imprimeMenuPrincipal();
			int opcao = ENTRADA.nextInt();
			if (opcao == 1) {
				processaInclusao();
			} else if (opcao == 2) {
				codigo = processaBusca();
				if (codigo != CODIGO_DESCONHECIDO) {
					processaAlteracao(codigo);
				} 
			} else if (opcao == 3) {
				codigo = processaBusca();
				if (codigo != CODIGO_DESCONHECIDO) {
					processaExclusao(codigo);
				}			
			} else if (opcao == 4) {
				processaBusca();
			} else if (opcao == 5) {
				System.out.println("Saindo do cadastro de produtos");
				System.exit(0);
			} else {
				System.out.println("Opção inválida!!");
			}
		} 
	}
	
	private void imprimeMenuPrincipal() {		
		System.out.println("1- Incluir");
		System.out.println("2- Alterar");
		System.out.println("3- Excluir");
		System.out.println("4- Buscar");
		System.out.println("5- Sair");
		System.out.print("Digite a opção: ");
	}	
	
	private void processaInclusao() {
		Produto produto = capturaProduto(CODIGO_DESCONHECIDO);
		String retornoValidacao = validar(produto);
		if (retornoValidacao == null) {
			boolean retornoRepositorio = repositorioProduto.incluir(produto);
			if (retornoRepositorio) {
				System.out.println("Produto incluído com sucesso!");
			} else {
				System.out.println("Erro na inclusão de produto!");
			}
		} else {
			System.out.println(retornoValidacao);
		}		
	}
	
	private void processaAlteracao(long codigo) {
		Produto produto = capturaProduto(codigo);
		String retornoValidacao = validar(produto);
		if (retornoValidacao == null) {
			boolean retornoRepositorio = repositorioProduto.alterar(produto);
			if (retornoRepositorio) {
				System.out.println("Produto alterado com sucesso!");
			} else {
				System.out.println("Erro na alteração de produto!");
			}
		} else {
			System.out.println(retornoValidacao);
		}		
	}
	
	private long processaBusca() {
		System.out.print("Digite o código: ");
		long codigo = ENTRADA.nextLong();
		Produto produto = repositorioProduto.buscar(codigo);
		if (produto == null) {
			System.out.println("Produto não encontrado!");
			return CODIGO_DESCONHECIDO;
		} else {
			System.out.println("Código: " + produto.getCodigo());
			System.out.println("Nome: " + produto.getNome());
			System.out.println("Preço: " + produto.getPreco());
			System.out.println("Tipo: " + produto.getTipo().getDescricao());
			return codigo;
		}
	}
	
	private void processaExclusao(long codigo) {
		boolean retornoRepositorio = repositorioProduto.excluir(codigo);
		if (retornoRepositorio) {
			System.out.println("Produto excluído com sucesso!");
		} else {
			System.out.println("Erro na exclusão de produto!");
		}
	}
	
	private Produto capturaProduto(long codigoDaAlteracao) {
		long codigo; 
		if (codigoDaAlteracao == CODIGO_DESCONHECIDO) {
			System.out.print("Digite o código: ");
			codigo = ENTRADA.nextLong();			
		} else {
			codigo = codigoDaAlteracao;
		}
		System.out.print("Digite o nome: ");
		String nome = ENTRADA.next();
		System.out.print("Digite o preço: ");
		double preco = ENTRADA.nextDouble();
		System.out.print("Digite o tipo de produto (1, 2 ou 3): ");
		int codigoTipo = ENTRADA.nextInt();
		TipoProduto tipo = TipoProduto.obterPorCodigo(codigoTipo);
		return new Produto(codigo, nome, preco, tipo);
	}
	
	private String validar(Produto produto) {
		int validacaoNome = produto.validarNome();
		if (!produto.codigoValido()) {
			return "Código inválido!";
		} else if (validacaoNome == Produto.NOME_NAO_INFORMADO) {
			return "Nome não informado!";
		} else if (validacaoNome == Produto.NOME_MUITO_CURTO) {
			return "Nome muito curto!";
		} else if (!produto.precoValido()) {
			return "Preço inválido!";
		} else if (!produto.tipoPreechido()) {
			return "Tipo não preenchido!";
		} else {
			return null;
		}
	}
}
