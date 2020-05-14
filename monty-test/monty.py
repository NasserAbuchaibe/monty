import unittest
from subprocess import check_output

cases = {
    "1.m" : ['3', '2', '1'],
    "2.m" : ['3000']
}

class TestStringMethods(unittest.TestCase):

    def testing(self):
        key = cases.keys()
        for k in key:
            quiting = "Hi"
            out = check_output(["./a.out", k])
            out = out.decode('utf8').split('\n')[:-1]
            self.assertEqual(out, cases[k])
            print("el test ha sido exitoso en el archivo", k)
            print("Resultado del archivo:", out, "concuerda con el resultado", cases[k])
            with self.assertRaises(TypeError):
                quiting.split(2)
                print("el test ha fallado en el archivo", k, "con resultado:", out)

if __name__ == '__main__':
    unittest.main()
