import re
code = "foo81(int junk,bool pie, float prank){int bar \n return bar}"
pattern = r"[A-Z a-z]+[0-9]*[A-Z a-z]*\([A-Z a-z]*[0-9]*[A-Z a-z]*[,[A-Z a-z]*[0-9]*[A-Z a-z]*]*\)\{[A-Z a-z]*[0-9]*[A-Z a-z]*[\n]*\}"

if re.match(pattern, code):
    print("Match")
else:
    print("Mismatch")