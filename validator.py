# python validator.py input.txt output.txt

import json
import re
import argparse

parser = argparse.ArgumentParser()
parser.add_argument('input')
parser.add_argument('output')
args = parser.parse_args()


class validator:
    def __init__(self):
        pass

    def check_email(email) -> bool:
        if re.match(r"\w+@[a-zA-Z_]+?\.[a-zA-Z]{2,6}", email):
            return True
        return False

    def check_height(height) -> bool:
        if re.match(r"^\d{1,2}\.\d{1,2}$", str(height)) and (float(height) > 1.00) and \
                (float(height) < 2.50):
            return True
        return False

    def check_inn(inn) -> bool:
        if re.match(r"^\d{12}$", inn):
            return True
        return False

    def check_passport(series) -> bool:
        if len(series) == 5 and re.match(r"\d{2}\s\d{2}", series):
            return True
        return False

    def check_occupation(occupation) -> bool:
        occupation_invalid = ['Монах', 'Паладин', 'Маг', 'Вышивальщица', 'Маникюрша', 'Цветочница']
        if occupation not in occupation_invalid and re.match(r"^([A-Z]|[А-Я])[\D]+$", occupation):
            return True
        return False

    def check_age(age) -> bool:
        if re.match(r"^\d{2}$", str(age)) and (int(age) > 14) and (int(age) < 99):
            return True
        return False

    def check_views(political_views) -> bool:
        political_views_invalid = ['согласен с действиями Гарроша Адского Крика на посту вождя Орды',
                                 'патриот независимой Темерии', 'поддерживает Братьев Бури',
                                 'поддерживает Имперский легион']
        if political_views not in political_views_invalid and \
                re.match(r"^[\D]+$", political_views):
            return True
        return False

    def check_worldview(worldview) -> bool:
        worldview_invalid = ['Культ проклятых', 'Культ Механикус', 'Храм Трибунала', 'Светское гачимученничество',
                           'культ богини Мелитэле', 'Девять божеств', 'Культ пророка Лебеды', 'Культ Вечного Огня']
        if worldview not in worldview_invalid and \
                re.match(r"^[\D]+$", worldview):
            return True
        return False

    def check_address(address: str) -> bool:
        if re.match(r"^(ул\.)?(Аллея)?\s[\w\.\s-]+\d+$", address):
            return True
        return False


data = json.load(open(args.input, encoding='windows-1251'))

valid_data = list()
email = 0
height = 0
inn = 0
passport_series = 0
occupation = 0
age = 0
political_views = 0
worldview = 0
address = 0

for person in data:
    temp = True
    if not validator.check_email(person["email"]):
        email += 1
        temp = False
    if not validator.check_height(person["height"]):
        height += 1
        temp = False
    if not validator.check_inn(person['inn']):
        inn += 1
        temp = False
    if not validator.check_passport(person['passport_series']):
        passport_series += 1
        temp = False
    if not validator.check_occupation(person["occupation"]):
        occupation += 1
        temp = False
    if not validator.check_age(person['age']):
        age += 1
        temp = False
    if not validator.check_views(person['political_views']):
        political_views += 1
        temp = False
    if not validator.check_worldview(person['worldview']):
        worldview += 1
        temp = False
    if not validator.check_address(person["address"]):
        address += 1
        temp = False
    if temp:
        valid_data.append(person)

out_put = open(args.output, 'w', encoding='utf-8')
data_for_output = json.dumps(valid_data, ensure_ascii=False, indent=4)
out_put.write(data_for_output)
out_put.close()

print()
print(f'Всего {len(data)} записей')
print(f'{len(valid_data)} валидных записей')
print(f'{len(data) - len(valid_data)} невалидных записей')
print()
print(f'Число невалидных почт:  {email}')
print(f'Число невалидных ростов: {height}')
print(f'Число невалидных ИНН: {inn}')
print(f'Число невалидных серий паспорта: {passport_series}')
print(f'Число невалидных занятостей {occupation}')
print(f'Число невалидных возрастов: {age}')
print(f'Число невалидных политических взглядов: {political_views}')
print(f'Число невалидных мировоззрений: {worldview}')
print(f'Число невалидных адрессов: {address}')