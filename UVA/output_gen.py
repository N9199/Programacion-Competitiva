import sys
import subprocess
import filecmp as cmp


file_original = "12145.cpp"
file_test = "12145test.cpp"
name_original = "original"
name_test = "tester"
ext = ".out"


def compile():
    print("Start compiling")
    compile = ['g++-7', '-std=c++11', '-lm',
               '-O2', '-w', '-Wfatal-errors']
    subprocess.call(
        compile + ['-o' + name_original + ext, file_original]
    )
    subprocess.call(
        compile + ['-o' + name_test + ext, file_test]
    )
    print("Finished compiling")


def eval_test(test, mult=False):
    print("Evaluating Test")
    out = "./{} < t > {}"
    with open(file="t", mode='w') as f:
        f.write(test)
    print(test)
    print(out.format(name_original + ext, name_original))
    subprocess.call(out.format(name_original + ext, name_original))
    subprocess.call(out.format(name_test + ext, name_test))

    print("Test evaluated")


def save_test():
    pass


def create_test():
    pass


if __name__ == "__main__":
    compile()
    eval_test('0*0=0\n=')
