import re


company_reg = re.compile('<span.+?company-title.+?>(.+?)</span>')


with open('fortune_companies.html', 'r', encoding='utf-8') as f:
    with open('fortune_companies.csv', 'w', encoding='utf-8') as f1:
        text = f.read()
        names = company_reg.findall(text)
        for name in names:
            f1.write(name + '\n')


