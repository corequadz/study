n = int(input())
e = "2.7182818284590452353602875"

if n == 0:
    print(3)
elif n == 25:
    print(e)
else:
    digits = e[0] + e[2:]
    num = int(digits[:n + 1])
    if int(digits[n + 1]) >= 5:
        num += 1
    s = str(num)
    print(s[0] + "." + s[1:])