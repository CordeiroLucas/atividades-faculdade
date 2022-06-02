# Created by danta at 31/05/2022
Feature: CalculadoraB
  Caluladora simples de operações matemáticas


  Scenario Outline: somar dois números
    Somar dois operadores e mostrar o resultado da soma
    Given o primeiro operador é <op1>
    And o segundo operador é <op2>
    When eu somo os operadores
    Then o resultado deve ser <resultado>

    Examples:
    |op1  |op2  |resultado|
    |2    |5    |7        |
    |8    |1    |9        |
    |3    |3    |6        |

  Scenario Outline: subtrair dois números
    Subtrai dois operadores e mostrar o resultado da subtração
    Given o primeiro operador é <op1>
    And o segundo operador é <op2>
    When eu subtraio os operadores
    Then o resultado deve ser <resultado>

    Examples:
    |op1  |op2  |resultado|
    |2    |5    |-3       |
    |8    |1    |7        |
    |3    |3    |0        |

  Scenario Outline: multiplicar dois números
    Multiplica dois operadores e mostrar o resultado da multiplição
    Given o primeiro operador é <op1>
    And o segundo operador é <op2>
    When eu multiplico os operadores
    Then o resultado deve ser <resultado>

    Examples:
    |op1  |op2  |resultado|
    |2    |5    |10       |
    |8    |-1   |-8       |
    |3    |3    |9        |

  Scenario Outline: dividir dois números
    Divide dois operadores e mostrar o resultado da divisão
    Given o primeiro operador é <op1>
    And o segundo operador é <op2>
    When eu divido os operadores
    Then o resultado deve ser <resultado>

    Examples:
    |op1  |op2  |resultado|
    |20   |5    |4        |
    |8    |1    |8        |
    |5    |2    |2.5      |

  Scenario Outline: potencia de num por expoente
    Potencia do operador 1 com expoente como operador 2
    Given o primeiro operador é <op1>
    And o segundo operador é <op2>
    When eu potencio o operador
    Then o resultado deve ser <resultado>

    Examples:
    |op1  |op2  |resultado|
    |3    |2    |9        |
    |5    |-1   |0.2      |
    |4    |3    |64       |