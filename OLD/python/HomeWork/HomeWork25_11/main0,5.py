class Book:
    def __init__(self, title, author, year):
        self.title = title
        self.author = author
        self.year = year

    def __str__(self):
        return f"Название: '{self.title}', Автор: {self.author}, Год: {self.year}"
    
    def __repr__(self):
        return f"Book('{self.title}', '{self.author}', {self.year})"

class Library:
    def __init__(self):
        self.books = []

    def add_book(self, book):
        self.books.append(book)
    
    def remove_book(self, book):
        self.books.remove(book)

    def __len__(self):
        return len(self.books)

library = Library()
book1 = Book("Война и мир", "Лев Толстой", 1869)
library.add_book(book1)
print(len(library))  
