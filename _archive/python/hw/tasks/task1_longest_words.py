
def longest_words(file):
    try:
        with open(file, 'r', encoding='utf-8') as f:
            content = f.read()
        
        words = content.replace('\n', ' ').split()
        
        if not words:
            return []
        
        max_length = max(len(word) for word in words)
        longest_words_list = [word for word in words if len(word) == max_length]
        
        return longest_words_list
    
    except FileNotFoundError:
        print(f"Файл {file} не найден!")
        return []
    except Exception as e:
        print(f"Ошибка при чтении файла: {e}")
        return []


def main():
    print("=" * 60)
    print("ЗАДАЧА 1: Поиск самых длинных слов в файле")
    print("=" * 60)
    
    article_file = "article.txt"
    
    print(f"Анализируем файл: {article_file}")
    print("\nСодержимое файла:")
    try:
        with open(article_file, 'r', encoding='utf-8') as f:
            for i, line in enumerate(f, 1):
                print(f"  {i}. {line.strip()}")
    except FileNotFoundError:
        print(f"Файл {article_file} не найден!")
        return
    
    print("\n" + "-" * 40)
    print("РЕЗУЛЬТАТ АНАЛИЗА:")
    print("-" * 40)
    
    result = longest_words(article_file)
    
    if result:
        print(f"Самые длинные слова (длина: {len(result[0])} символов):")
        for word in result:
            print(f"  - '{word}'")
        
        print(f"\nВсего найдено слов максимальной длины: {len(result)}")
    else:
        print("Не удалось найти слова в файле.")
    
    print("\n" + "=" * 60)



main()