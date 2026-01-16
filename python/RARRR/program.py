import re;

# re.search() 
# re.fullmatch полное совпадение 
# re.split разделяет 
# re.findall создает массив найденных элементнов 
# re.finditer нахождение текста и его позиции 
# re.sub найти => заменить => куда заменить

# print(re.findall(r'\d\d.\d\d.\d{4}', r'эта строка была написана в 12.12.2026. в 15.07.2030 он погиб'))

# -----

testString = 'Name: Max. Birthdate: 18 july, 1998'

reg = r"Name: ([a-zA-z]+)\. Birthdate: (\d+) ([a-zA-z]+), (\d+)"
match = re.search(reg,testString)

if match != None:
    print('Вся совпавшая строка: ', match.group(0))
    print('Группа 1 - имя: ', match.group(1))
    print('группа 2 - дата рождения: ', match.group(2))
    print('Группа 3 - месяц рождения: ', match.group(3))
    

string = 'my_dsfsd'

match = re.match(r'[a-zA-Z0-9_\-!?]{8,16}$', string)
if match:
    print('correct password')

else:
    print('Incorrect password')
    