import sys
import subprocess


def main():
    args = sys.argv
    command = ["ls", "-l"]
    if len(args) > 1:
        command.extend(args)
    result = subprocess.check_output(command)
    print(result)

if __name__ == "__main__":
    main()