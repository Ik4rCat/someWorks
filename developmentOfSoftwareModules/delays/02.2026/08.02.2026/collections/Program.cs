using System;
using System.Collections;
using System.Collections.Generic;

namespace Collections
{
    // ─────────────────────────────────────
    //  Задание 1 — ArrayList vs List<T>
    // ─────────────────────────────────────
    class Task1
    {
        public static void Run()
        {
            Console.WriteLine("=== Task 1: ArrayList vs List<T> ===");

            // Необобщённая коллекция
            ArrayList objectList = new ArrayList() { 1, 2, "string", 'c', 2.0f };
            objectList.Add(45.8);
            objectList.Add("string2");
            objectList.RemoveAt(0);
            Console.WriteLine("ArrayList:");
            foreach (object o in objectList) Console.WriteLine("  " + o);
            Console.WriteLine("  Count: " + objectList.Count);

            // Обобщённая коллекция
            List<int> numbers = new List<int>() { 1, 2, 3, 45 };
            numbers.Add(6);
            numbers.AddRange(new int[] { 7, 8, 9 });
            numbers.Insert(0, 666);
            numbers.RemoveAt(1);
            numbers.Sort();
            Console.WriteLine("List<int> (sorted):");
            foreach (int i in numbers) Console.Write("  " + i);
            Console.WriteLine();

            // Поиск
            Console.WriteLine("  Contains 8: " + numbers.Contains(8));
            Console.WriteLine("  IndexOf 8:  " + numbers.IndexOf(8));

            // List объектов
            List<Person> people = new List<Person>
            {
                new Person { Name = "Том",  Age = 25 },
                new Person { Name = "Билл", Age = 30 }
            };
            Console.WriteLine("People:");
            foreach (Person p in people)
                Console.WriteLine($"  {p.Name}, {p.Age}");
        }
    }

    // ─────────────────────────────────────
    //  Задание 2 — LinkedList<T>
    // ─────────────────────────────────────
    class Task2
    {
        public static void Run()
        {
            Console.WriteLine("\n=== Task 2: LinkedList<T> ===");

            LinkedList<int> numbers = new LinkedList<int>();
            numbers.AddLast(1);
            numbers.AddFirst(2);
            numbers.AddAfter(numbers.Last, 3);
            Console.Write("List: ");
            foreach (int i in numbers) Console.Write(i + " "); // 2 1 3
            Console.WriteLine();

            LinkedList<Person> persons = new LinkedList<Person>();
            LinkedListNode<Person> tom = persons.AddLast(new Person { Name = "Tom" });
            persons.AddLast(new Person { Name = "John" });
            persons.AddFirst(new Person { Name = "Bill" });

            // Bill ← Tom → John
            Console.WriteLine("Before Tom: " + tom.Previous.Value.Name);
            Console.WriteLine("After Tom:  " + tom.Next.Value.Name);
        }
    }

    // ─────────────────────────────────────
    //  Задание 3 — Queue<T> и Stack<T>
    // ─────────────────────────────────────
    class Task3
    {
        public static void Run()
        {
            Console.WriteLine("\n=== Task 3: Queue<T> и Stack<T> ===");

            // Очередь FIFO
            Queue<int> queue = new Queue<int>();
            queue.Enqueue(3);
            queue.Enqueue(5);
            queue.Enqueue(8);
            Console.WriteLine("Queue Peek: " + queue.Peek());
            Console.WriteLine("Dequeue:    " + queue.Dequeue());
            Console.WriteLine("Queue Count: " + queue.Count);

            Queue<Person> persons = new Queue<Person>();
            persons.Enqueue(new Person { Name = "Tom" });
            persons.Enqueue(new Person { Name = "Bill" });
            persons.Enqueue(new Person { Name = "John" });
            Console.WriteLine("First in queue: " + persons.Peek().Name);
            Console.WriteLine("Dequeued: " + persons.Dequeue().Name);

            // Стек LIFO
            Stack<int> stack = new Stack<int>();
            stack.Push(3);
            stack.Push(5);
            stack.Push(8);
            Console.WriteLine("\nStack Pop: " + stack.Pop()); // 8
            Console.WriteLine("Stack Peek: " + stack.Peek()); // 5

            Stack<Person> personStack = new Stack<Person>();
            personStack.Push(new Person { Name = "Tom" });
            personStack.Push(new Person { Name = "Bill" });
            personStack.Push(new Person { Name = "John" });
            Console.Write("Stack (LIFO): ");
            foreach (Person p in personStack) Console.Write(p.Name + " ");
            Console.WriteLine();
            Console.WriteLine("Popped: " + personStack.Pop().Name);
        }
    }

    // ─────────────────────────────────────
    //  Задание 4 — Dictionary<TKey, TValue>
    // ─────────────────────────────────────
    class Task4
    {
        public static void Run()
        {
            Console.WriteLine("\n=== Task 4: Dictionary<TKey, TValue> ===");

            var countries = new Dictionary<int, string>
            {
                { 1, "Russia" },
                { 2, "USA" },
                { 3, "Great Britain" },
                { 4, "France" },
                { 5, "China" }
            };

            foreach (var kv in countries)
                Console.WriteLine($"  {kv.Key} - {kv.Value}");

            countries[4] = "Spain";
            countries.Remove(2);
            Console.WriteLine("After edit:");
            foreach (var kv in countries)
                Console.WriteLine($"  {kv.Key} - {kv.Value}");

            // Словарь объектов
            var people = new Dictionary<char, Person>
            {
                ['b'] = new Person { Name = "Bill" },
                ['t'] = new Person { Name = "Tom" },
                ['j'] = new Person { Name = "John" }
            };
            Console.WriteLine("Keys:");
            foreach (char c in people.Keys) Console.Write("  " + c);
            Console.WriteLine("\nValues:");
            foreach (Person p in people.Values) Console.Write("  " + p.Name);
            Console.WriteLine();
        }
    }

    // ─────────────────────────────────────
    //  Задание 5 — IEnumerable + yield
    // ─────────────────────────────────────
    class Book
    {
        public string Name { get; set; }
        public Book(string name) { Name = name; }
    }

    class Library : IEnumerable
    {
        private Book[] books = {
            new Book("Отцы и дети"),
            new Book("Война и мир"),
            new Book("Евгений Онегин")
        };

        public int Length => books.Length;

        public Book this[int index]
        {
            get => books[index];
            set => books[index] = value;
        }

        // Реализация IEnumerable через yield
        public IEnumerator GetEnumerator()
        {
            for (int i = 0; i < books.Length; i++)
                yield return books[i];
        }

        // Именованный итератор — первые max книг
        public IEnumerable GetBooks(int max)
        {
            for (int i = 0; i < max; i++)
            {
                if (i == books.Length) yield break;
                yield return books[i];
            }
        }
    }

    class Task5
    {
        public static void Run()
        {
            Console.WriteLine("\n=== Task 5: IEnumerable + yield ===");

            Library lib = new Library();
            Console.WriteLine("Все книги:");
            foreach (Book b in lib) Console.WriteLine("  " + b.Name);

            Console.WriteLine("Первые 2:");
            foreach (Book b in lib.GetBooks(2)) Console.WriteLine("  " + b.Name);

            lib[0] = new Book("Преступление и наказание");
            Console.WriteLine("После замены [0]: " + lib[0].Name);
        }
    }

    // ─────────────────────────────────────
    //  Вспомогательный класс
    // ─────────────────────────────────────
    class Person
    {
        public string Name { get; set; }
        public int Age { get; set; }
    }

    // ─────────────────────────────────────
    //  Точка входа
    // ─────────────────────────────────────
    class Program
    {
        static void Main(string[] args)
        {
            Task1.Run();
            Task2.Run();
            Task3.Run();
            Task4.Run();
            Task5.Run();
        }
    }
}
