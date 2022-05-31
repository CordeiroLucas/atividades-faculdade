from behave import *

from src.calculatorB import CalculatorB

use_step_matcher("re")


@given("o primeiro operador é 6")
def set_op1(context):
        
        # :type context: behave.runner.context
        
        context.op1 = 6
        
@step("o segundo operador é 4")
def set_op2(context):
        
        # :type context: behave.runner.context
        
        context.op2 = 4
        
@when("eu somar os operadores")
def soma(context):
        
        # :type context: behave.runner.context
        
        calculadora = CalculatorB()
        context.resultado = calculadora.soma(context.op1, context.op2)
        
@step("o resultado deve ser 10")
def resultado(context):
        
        # :type context: behave.runner.context
        
        assert context.resultado == 11
        