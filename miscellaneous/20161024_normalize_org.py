import pymorphy2


morph = pymorphy2.MorphAnalyzer()


with open('fortune_companies.csv', 'r', encoding='utf-8') as f:
    with open('dic_org_fortune_companies.txt', 'w', encoding='utf-8') as f1:
        for line in f:
            s = ''
            line = line.strip()
            words = line.split(' ')
            for word in words:
                if word.isupper():
                    norm_word = word.lower()
                else:
                    norm_word = morph.parse(word)[0].normal_form
                s += norm_word + ' '
            f1.write(s + '\n')