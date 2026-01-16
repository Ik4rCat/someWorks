import re
import string;

# re.search() 
# re.fullmatch полное совпадение 
# re.split разделяет 
# re.findall создает массив найденных элементнов 
# re.finditer нахождение текста и его позиции 
# re.sub найти => заменить => куда заменить

# print(re.findall(r'\d\d.\d\d.\d{4}', r'эта строка была написана в 12.12.2026. в 15.07.2030 он погиб'))

# -----

# testString = 'Name: Max. Birthdate: 18 july, 1998'

# reg = r"Name: ([a-zA-z]+)\. Birthdate: (\d+) ([a-zA-z]+), (\d+)"
# match = re.search(reg,testString)

# if match != None:
#     print('Вся совпавшая строка: ', match.group(0))
#     print('Группа 1 - имя: ', match.group(1))
#     print('группа 2 - дата рождения: ', match.group(2))
#     print('Группа 3 - месяц рождения: ', match.group(3))
#
#string = 'my_dsfsd'

#match = re.match(r'[a-zA-Z0-9_\-!?]{8,16}$', string)
#if match:
#    print('correct password')
#
#else:
#    print('Incorrect password')

# -----
print('-----')


text = '''
My phone number is +7(911)666-55-55 and my office number is +1-202-555-0198.
I will wait your call at 2027/12/01.
Visit my <a href="https://example.com" class="contact-link" id="main-link">website</a> or check out
<span data-info="user-profile" style="color:blue;">my profile</span>.'''

match = re.findall(r'\+\d{1,3}\(\d{3}\)\d{3}-\d{2}-\d{2}', text)
match2 = re.findall(r'\d{4}/\d{2}/\d{2}', text)
htmlTags = re.findall(r'<[^>]+>', text)
htmlAttrs = re.findall(r'([a-zA-Z\-]+)=["\'][^"\']*["\']', text)

if match and match2 and htmlTags and htmlAttrs != None:
    print('Found phone number(s):', match)
    print('Found date(s):', match2)
    print('Found HTML tag(s):', htmlTags)
    print('Found HTML attribute(s):', htmlAttrs)

passphrase = '{|4lter-f0mhGv4n\|!}'

passphr4se = re.match(r'[a-zA-Z0-9_|\-!{}]{8,16}$', passphrase)
if passphr4se:
    print('correct password')
else:
    print('Incorrect password')
re.sub(re, r'\3')