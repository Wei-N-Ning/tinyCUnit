#!/usr/bin/env python

import os
import re
import sys


pattern = '^TINYTEST.*?(\w+).*$'


def readme():
    sys.stdout.write(
        "\nCreate main() function.\n\n"
        "1) print main() function to stdout:\n"
        "createMainFunc.py sourceFile.c\n\n"
        "2) print main() function to outFile.c:\n"
        "createMainFunc.py sourceFile.c outFile.c\n\n"
    )


def in_file():
    if len(sys.argv) < 2:
        return None
    return sys.argv[1]


def out_file():
    if len(sys.argv) < 3:
        return None
    return sys.argv[2]


def process(path, out):
    """

    Args:
        path (str):
        out (file): a file-like object

    Returns:
        int: number of test functions
    """
    func_names = list()
    with open(path, 'r') as fp:
        for line in fp.xreadlines():
            r = re.search(pattern, line)
            if not r:
                continue
            func_names.append(r.groups()[0])
    if not func_names:
        return 0
    out.write(
        "int main(int argc, char **argv) {\n"
    )
    for func_name in func_names:
        out.write("    AddTinyTest({});\n".format(func_name))
    out.write(
        "    RUN_ALL_TESTS();\n"
        "}\n"
    )
    out.flush()


def main():
    in_path = in_file()
    if not (in_path and os.path.isfile(in_path)):
        readme()
        sys.exit(1)
    out_path = out_file()
    if out_path and os.access(os.path.dirname(out_path), os.W_OK):
        f = open(out_path, 'w')
    else:
        f = sys.stdout
    process(in_path, f)
    if out_path:
        f.close()


if __name__ == '__main__':
    main()
