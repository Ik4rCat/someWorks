import os
from pathlib import Path


def print_docs(directory):
    try:
        if not os.path.exists(directory):
            print(f"Директория {directory} не существует!")
            return
        
        if not os.path.isdir(directory):
            print(f"{directory} не является директорией!")
            return
        
        print(f"\nСодержимое директории: {directory}")
        print("=" * 50)
        
        for root, dirs, files in os.walk(directory):
            level = root.replace(directory, '').count(os.sep)
            indent = '  ' * level
            
            print(f"{indent}{os.path.basename(root)}/")
            
            sub_indent = '  ' * (level + 1)
            for file in files:
                print(f"{sub_indent}{file}")
    
    except Exception as e:
        print(f"Ошибка при обходе директории: {e}")


def print_docs_with_stats(directory):
    try:
        if not os.path.exists(directory):
            print(f"Директория {directory} не существует!")
            return
        
        if not os.path.isdir(directory):
            print(f"{directory} не является директорией!")
            return
        
        print(f"\nДЕТАЛЬНОЕ СОДЕРЖИМОЕ ДИРЕКТОРИИ: {directory}")
        print("=" * 60)
        
        total_files = 0
        total_dirs = 0
        
        for root, dirs, files in os.walk(directory):
            level = root.replace(directory, '').count(os.sep)
            indent = '  ' * level
            
            total_dirs += 1
            total_files += len(files)
            
            print(f"{indent}{os.path.basename(root)}/")
            
            sub_indent = '  ' * (level + 1)
            for file in files:
                file_path = os.path.join(root, file)
                file_size = os.path.getsize(file_path)
                print(f"{sub_indent}{file} ({file_size} байт)")
        
        print("\n" + "=" * 60)
        print("СТАТИСТИКА:")
        print(f"Всего директорий: {total_dirs}")
        print(f"Всего файлов: {total_files}")
        print("=" * 60)
        
    except Exception as e:
        print(f"Ошибка при обходе директории: {e}")


def main():
    print("=" * 60)
    print("ЗАДАЧА 3: Вывод содержимого директории")
    print("=" * 60)
    
    current_dir = "."
    print(f"1. Содержимое текущей директории: {os.path.abspath(current_dir)}")
    print_docs(current_dir)
    
    parent_dir = ".."
    print(f"\n2. Содержимое родительской директории: {os.path.abspath(parent_dir)}")
    print_docs(parent_dir)
    
    print(f"\n3. Детальная информация о текущей директории:")
    print_docs_with_stats(current_dir)
    
    home_dir = os.path.expanduser("~")
    print(f"\n4. Содержимое домашней директории: {home_dir}")
    print("(Показываем только первые несколько уровней для краткости)")
    
    try:
        if os.path.exists(home_dir):
            print(f"\nСодержимое директории: {home_dir}")
            print("=" * 50)
            
            count = 0
            for root, dirs, files in os.walk(home_dir):
                if count >= 10:
                    print("  ... (показаны только первые 10 элементов)")
                    break
                
                level = root.replace(home_dir, '').count(os.sep)
                if level > 2:
                    continue
                
                indent = '  ' * level
                print(f"{indent}{os.path.basename(root)}/")
                
                sub_indent = '  ' * (level + 1)
                for file in files[:5]:
                    print(f"{sub_indent}{file}")
                
                count += 1
    except Exception as e:
        print(f"Ошибка при обходе домашней директории: {e}")
    
    print("\n" + "=" * 60)


main()