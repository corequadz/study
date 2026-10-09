from math import *
numbers = "0123456789."
operators = "+-*/()="
priority = {
    '==': 0,
    '+': 1,
    '-': 1,
    '*': 2,
    '/': 2,
    'u-': 3
}


def to_postfix(s):
    res = []
    opers = []
    cur_num = ""
    cur_word = ""
    s = s.replace(' ', '')

    for i in range(len(s)):
        elm = s[i]

        if elm in operators:
            if cur_num != '':
                res.append(cur_num)
                cur_num = ''

            if elm == '-' and (i == 0 or s[i - 1] in "+-*/(="): 
                elm = 'u-'
            if elm == '=' and i > 0 and s[i - 1] == '=':
                continue  
            if elm == '=' and i + 1 < len(s) and s[i + 1] == '=':
                elm = '=='

            if elm == '(':
                opers.append(elm)
            elif elm == ')':
                while opers and opers[-1] != '(':
                    res.append(opers.pop())
                opers.pop()
                if opers and opers[-1] == 'tan':
                    res.append(opers.pop())
            
            elif elm == 'u-':
                opers.append(elm)
            else:
                while opers and opers[-1] != '(' and priority[opers[-1]] >= priority[elm]:
                    res.append(opers.pop())
                opers.append(elm)

        elif elm in numbers:
            cur_num += elm
        elif elm.isalpha():
            cur_word += elm
            if cur_word == "tan":
                opers.append("tan")
                cur_word = ''

    if cur_num != '':
        res.append(cur_num)

    while opers:
        res.append(opers.pop())

    return ' '.join(res)


def to_prefix(s):
    post_str = to_postfix(s)
    st = []
    for token in post_str.split():
        if token in ("u-", "tan"):
            a = st.pop()
            st.append(f"{token} {a}")
        elif token in ("+", "-", "*", "/", "=="):
            b = st.pop()
            a = st.pop()
            st.append(f"{token} {a} {b}")
        else:
            st.append(token)

    return st[0]


def calculate(nums, operator):
    if operator == "u-":
        nums.append(-nums.pop())
        return
    elif operator == "tan":
        nums.append(tan(nums.pop()))
        return

    b = nums.pop()
    a = nums.pop()
    if operator == '+':
        nums.append(a + b)
    elif operator == '-':
        nums.append(a - b)
    elif operator == '*':
        nums.append(a * b)
    elif operator == '/':
        nums.append(a / b)
    elif operator == '==':
        nums.append(True if a == b else False)


def parser(s):
    nums = []
    opers = []
    cur_num = ""
    cur_word = ""
    s = s.replace(' ', '')

    for i in range(len(s)):
        elm = s[i]

        if elm in operators:
            if cur_num != '':
                nums.append(float(cur_num))
                cur_num = ''

            if elm == '-' and (i == 0 or s[i - 1] in "+-*/(="): 
                elm = 'u-'

            if elm == '=' and i > 0 and s[i - 1] == '=':
                continue  
            if elm == '=' and i + 1 < len(s) and s[i + 1] == '=':
                elm = '=='

            if elm == '(':
                opers.append(elm)
            elif elm == ')':
                while opers and opers[-1] != '(':
                    calculate(nums, opers.pop())
                opers.pop()
                if opers and opers[-1] == 'tan':
                    calculate(nums, opers.pop())
            
            elif elm == 'u-':
                opers.append(elm)
            else:
                while opers and opers[-1] != '(' and priority[opers[-1]] >= priority[elm]:
                    calculate(nums, opers.pop())
                opers.append(elm)

        elif elm in numbers:
            cur_num += elm
        elif elm.isalpha():
            cur_word += elm
            if cur_word == "tan":
                opers.append("tan")
                cur_word = ''

    if cur_num != '':
        nums.append(float(cur_num))

    while opers:
        calculate(nums, opers.pop())

    return nums[0]


s = input("Введите выражение: ")
print("Результат:", parser(s))
print("Постфиксная запись:", to_postfix(s))
print("Префиксная запись:", to_prefix(s))


