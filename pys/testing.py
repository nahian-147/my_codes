import subprocess

p = int(subprocess.check_output(["./testing","5"]).decode())

print(p*p)
