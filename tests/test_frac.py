import ctypes
import os

lib_path = os.path.join(os.path.dirname(__file__), "libcfraction.so")
lib = ctypes.CDLL(lib_path)

class Fraction(ctypes.Structure):
    _fields_ = [("num", ctypes.c_int64), ("den", ctypes.c_int64)]

lib.frac_create.argtypes = [ctypes.c_int64, ctypes.c_int64]
lib.frac_create.restype = Fraction

lib.frac_add.argtypes = [Fraction, Fraction]
lib.frac_add.restype = Fraction

lib.frac_sub.argtypes = [Fraction, Fraction]
lib.frac_sub.restype = Fraction

lib.frac_mul.argtypes = [Fraction, Fraction]
lib.frac_mul.restype = Fraction

lib.frac_div.argtypes = [Fraction, Fraction]
lib.frac_div.restype = Fraction

lib.to_double.argtypes = [Fraction]
lib.to_double.restype = ctypes.c_double

def test_operations():
    a = lib.frac_create(1, 2)  
    b = lib.frac_create(1, 3)  

    c = lib.frac_add(a, b)
    print(f"Сложение: {c.num}/{c.den}")
    assert c.num == 5 and c.den == 6

    c = lib.frac_sub(a, b)
    print(f"Вычитание: {c.num}/{c.den}")
    assert c.num == 1 and c.den == 6

    c = lib.frac_mul(a, b)
    print(f"Умножение: {c.num}/{c.den}")
    assert c.num == 1 and c.den == 6

    c = lib.frac_div(a, b)
    print(f"Деление: {c.num}/{c.den}")
    assert c.num == 3 and c.den == 2

    d = lib.to_double(a)
    print(f"Каст в double: {d}")
    assert abs(d - 0.5) < 1e-9

if __name__ == "__main__":
    test_operations()
    print("Все тесты успешно пройдены!")
