def read_file(filename):
    with open(filename, "rt") as ifh:
        lines = ifh.readlines()
    return [line.replace("\n", "") for line in lines]