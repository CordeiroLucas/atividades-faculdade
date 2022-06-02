# ALUNOS: LUCAS PACHECO, LORENZO MAZZULI, ANTHONY KEVIN
# TURMA: B
# PRÁTICA TDD

import numbers

class CalcError(Exception):
    pass

class CalculatorB(object):
    
    def _check_type(self, op):
        if (op % 1 != 0):
            raise CalcError(f"{op} não é um número Inteiro!")
        else:
            op = int(op)
        if not isinstance(op,numbers.Number):
            raise CalcError(f"\"{op}\" não é do tipo número!")
        if not isinstance(op, numbers.Integral):
            raise CalcError(f"{op} não é um número Inteiro!")
        
    def _check_fract(self, a, b):
            decNum = a / b
            frac = decNum % 1
            if frac == 0:
                intNum = int(decNum)
                return intNum
            else:
                raise CalcError(f"{decNum} não é um número Inteiro!")
    
    #soma OK
    def soma(self,a,b):
        self._check_type(a)
        self._check_type(b)
        return a + b
    #soma OK

    #sub OK
    def subtracao(self,a,b):
        self._check_type(a)
        self._check_type(b)
        self._check_type(a-b)
        return a - b
    #sub OK

    # teste mult ok
    def multiplicacao(self,a,b):
        self._check_type(a)
        self._check_type(b)
        self._check_type(a*b)
        return a * b
    # teste mult ok

    # teste div ok
    def divisao(self,a,b):
        self._check_type(a)
        self._check_type(b)
        result = self._check_fract(a, b)
        return result
    # teste div ok
    
    # teste pot ok
    def potencia(self,a,b):
        self._check_type(a)
        self._check_type(b)
        self._check_type(a**b)
        return a ** b
    # teste pot ok