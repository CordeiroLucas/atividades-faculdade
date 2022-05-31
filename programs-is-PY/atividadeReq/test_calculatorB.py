# ALUNOS: LUCAS PACHECO, LORENZO MAZZULI, ANTHONY KEVIN
# TURMA: B
# PRÁTICA TDD

import pytest

from calculatorB import CalculatorB, CalcError

@pytest.mark.parametrize("a,b,res",
                           [(7,-2,5), #tem que dar errado 1 ok
                            (-1,2,1), #tem que dar errado 2 ok 
                            ("3",2,5), #tem que dar errado 3 ok
                            (10,"12",22), #tem que dar errado 4 ok
                            ("30", -15, 15), #tem que dar errado 5 ok 
                            (0,0,0), #tem que dar certo 01 ok
                            (12,15,27), #tem que dar certo 02 ok
                            (3,3,5),  #tem que dar errado 6 ok
                            (2.75, 1.25,4)]) #tem que dar errado 7 ok
# teste soma ok
def test_soma(a,b,res):
    calculadora = CalculatorB()
    res_calc = calculadora.soma(a,b)
    try:
        assert res == res_calc
    except:
        raise CalcError(f"O resultado {res} está errado! - Esperado: {res_calc}")
# teste soma ok

@pytest.mark.parametrize("a,b,res",
                           [(7,2,5), #tem que dar certo 01 ok
                            (3,2,1), #tem que dar certo 02 ok
                            (-1,2,-3), #tem que dar errado 1 ok
                            (2,4,-2), #tem que dar errado 2 ok
                            ("3",1,2), #tem que dar errado 3 ok
                            (7,"5",2), #tem que dar errado 4 ok
                            (1,0,-1), #tem que dar errado 5 ok
                            (5.25, 4.25, 1)]) #tem que dar errado 6 ok

# teste sub ok
def test_subtracao(a,b,res):
    calculadora = CalculatorB()
    res_calc = calculadora.subtracao(a, b)
    try:
        assert res == res_calc
    except:
        raise CalcError(f"O resultado {res} está errado! - Esperado: {res_calc}")
# teste sub ok

@pytest.mark.parametrize("a,b,res",
                           [(7,2,14), #tem que dar certo 01 ok
                            (3,2,3), #tem que dar errado 1 ok
                            (-1,2,-2), #tem que dar errado 2 ok
                            (2,4,8), #tem que dar certo 02 ok
                            ("3",1,3), #tem que dar errado 3 ok
                            (7,"5",35), #tem que dar errado 4 ok
                            (1,0,0), #tem que dar certo 03 ok
                            (1,2.3,2.3)]) #tem que dar errado 5 ok

# teste mult ok
def test_multiplicacao(a,b,res):
    calculadora = CalculatorB()
    res_calc = calculadora.multiplicacao(a,b)
    try:
        assert res == res_calc
    except:
        raise CalcError(f"O resultado {res} está errado! - Esperado: {res_calc}")
# teste mult ok

@pytest.mark.parametrize("a,b,res",
                           [(8,2,4), # tem que dar certo 01 ok 
                            (9,3,3), # tem que dar certo 02 ok
                            (-4,2,-2), # tem que dar errado 1 ok
                            (6,-3,-2), # tem que dar errado 2 ok
                            ("2",1,2), # tem que dar errado 3 ok
                            (6,"3",2), # tem que dar errado 4 ok
                            (7,2,3.5), # tem que dar errado 5 ok
                            (2.5, 2.5, 1)]) # tem que dar errado 6 ok

# teste div ok
def test_divisao(a,b,res):
    calculadora = CalculatorB()
    res_calc = calculadora.divisao(a, b)
    try:
        assert res == res_calc
    except:
        raise CalcError(f"O resultado {res} está errado! - Esperado: {res_calc}")
# teste div ok

@pytest.mark.parametrize("a,b,res",
                          [(2,2,4), # tem que dar certo 01 ok 
                          (3,8,6561), # tem que dar certo 02 ok 
                          (0,2,0), # tem que dar certo 03 ok
                          (-4,1,-4), # tem que dar errado 1 ok 
                          ("1",1,1), # tem que dar errado 2 ok
                          (4,2.00,16), # tem que dar errado 3 ok
                          (2,3,-8)]) # tem que dar errado 4 ok

# teste pot ok
def test_potencia_tipo(a,b,res):
   calculadora = CalculatorB()
   res_calc = calculadora.potencia(a,b)
   try:
       assert res == res_calc
   except:
       raise CalcError(f"O resultado {res} está errado! - Esperado: {res_calc}")
# teste pot ok