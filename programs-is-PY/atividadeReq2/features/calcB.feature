Feature: CalculadoraB
	Calculadora simples de operações matemáticas

Scenario: somar dois números
	Somar dois operadores e mostrar o resultado da soma
	Given o primeiro operador é 6
	And o segundo operador é 4
	When eu somar os operadores
	Then o resultado deve ser 10