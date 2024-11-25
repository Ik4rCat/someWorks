class Book:
    def __init__(self, title, author, year):
        self.title = title
        self.author = author
        self.year = year

    def __str__(self):
        return f"Название: '{self.title}', Автор: {self.author}, Год: {self.year}"

    def __repr__(self):
        return f"Book('{self.title}', '{self.author}', {self.year})"

book = Book("Война и мир", "Лев Толстой", 1869)
print(book) 
print(repr(book))
