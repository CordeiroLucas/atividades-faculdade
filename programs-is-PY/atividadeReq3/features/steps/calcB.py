from behave import *

from src.calculatorB import CalculatorB



@given("o primeiro operador é {op1}")
def set_op1(context, op1):
    """
    :type context: behave.runner.Context
    """
    context.op1 = float(op1)


@step("o segundo operador é {op2}")
def set_op2(context, op2):
    """
    :type context: behave.runner.Context
    """
    context.op2 = float(op2)


@when("eu somo os operadores")
def soma(context):
    """
    :type context: behave.runner.Context
    """
    calculadora = CalculatorB()
    context.resultado = calculadora.soma(context.op1, context.op2)


@then("o resultado deve ser {resultado}")
def result(context, resultado):
    """
    :type context: behave.runner.Context
    """
    assert context.resultado == float(resultado)


@when("eu subtraio os operadores")
def subtrair(context):
    """
    :type context: behave.runner.Context
    """
    calculadora = CalculatorB()
    context.resultado = calculadora.subtracao(context.op1, context.op2)
    
@when("eu multiplico os operadores")
def multiplicar(context):
    
    calculadora = CalculatorB()
    context.resultado = calculadora.multiplicacao(context.op1, context.op2)

@when("eu divido os operadores")
def dividir(context):
    
    calculadora = CalculatorB()
    context.resultado = calculadora.divisao(context.op1, context.op2)
    
@when("eu potencio o operador")
def potenciar(context):
    
    calculadora = CalculatorB()
    context.resultado = calculadora.potencia(context.op1, context.op2)
    