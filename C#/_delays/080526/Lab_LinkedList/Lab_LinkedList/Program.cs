using System.Diagnostics;

// ══════════════════════════════════════════════════════════════════
//  Задание 6 — «Аналитик логов»: List<T> vs LinkedList<T>
// ══════════════════════════════════════════════════════════════════

static void FillList(int count)
{
    var list = new List<string>();
    for (int i = 0; i < count; i++)
        list.Insert(0, $"[EVENT] Log entry #{i}");
}

static void FillLinkedList(int count)
{
    var list = new LinkedList<string>();
    for (int i = 0; i < count; i++)
        list.AddFirst($"[EVENT] Log entry #{i}");
}

const int N = 10_000;

Console.WriteLine("=== Задание 6: List vs LinkedList ===");
Console.WriteLine($"Вставка {N} строк в начало коллекции\n");

var sw = Stopwatch.StartNew();
FillList(N);
sw.Stop();
Console.WriteLine($"List<string>       Insert(0, item)  → {sw.ElapsedMilliseconds} мс  (O(n) — каждый раз сдвигает все элементы)");

sw.Restart();
FillLinkedList(N);
sw.Stop();
Console.WriteLine($"LinkedList<string> AddFirst(item)   → {sw.ElapsedMilliseconds} мс  (O(1) — просто меняет указатель на голову)");

Console.WriteLine();
Console.WriteLine("Вывод: LinkedList выигрывает при частых вставках в начало/середину.");
Console.WriteLine("       List лучше когда нужен быстрый доступ по индексу (list[i] — O(1)).");

Console.WriteLine();
Console.WriteLine(new string('═', 60));
Console.WriteLine();

// ══════════════════════════════════════════════════════════════════
//  Задание 7 — «История браузера»: LinkedList как стек истории
// ══════════════════════════════════════════════════════════════════

Console.WriteLine("=== Задание 7: История браузера ===\n");

var history = new LinkedList<string>();

// Добавляем 5 адресов
history.AddLast("https://google.com");
history.AddLast("https://github.com");
history.AddLast("https://youtube.com");
history.AddLast("https://stackoverflow.com");
history.AddLast("https://docs.microsoft.com");

Console.WriteLine("История (в порядке добавления):");
foreach (var url in history)
    Console.WriteLine($"  {url}");

// Указатель на «текущую» страницу — последний добавленный
LinkedListNode<string>? current = history.Last;
Console.WriteLine($"\nТекущая страница: {current?.Value}");

// ── Команды навигации ──────────────────────────────────────────

void Back()
{
    if (current?.Previous == null)
    { Console.WriteLine("  [Back] Дальше некуда — это начало истории."); return; }
    current = current.Previous;
    Console.WriteLine($"  [Back] → {current.Value}");
}

void Next()
{
    if (current?.Next == null)
    { Console.WriteLine("  [Next] Дальше некуда — это последняя страница."); return; }
    current = current.Next;
    Console.WriteLine($"  [Next] → {current.Value}");
}

void Navigate(string url)
{
    // Удаляем все узлы после текущего (ветка «вперёд» срезается)
    while (current?.Next != null)
        history.RemoveLast();

    history.AddLast(url);
    current = history.Last;
    Console.WriteLine($"  [Nav]  → {current!.Value}  (всё «вперёд» удалено)");
}

Console.WriteLine();
Console.WriteLine("--- Навигация ---");
Back();   // stackoverflow
Back();   // youtube
Back();   // github
Next();   // youtube

Console.WriteLine();
Console.WriteLine("Переходим на новую страницу посреди истории:");
Navigate("https://habr.com");   // docs.microsoft и stackoverflow удалятся

Console.WriteLine();
Console.WriteLine("История после Navigate:");
foreach (var url in history)
    Console.WriteLine($"  {url}");
Console.WriteLine($"Текущая: {current?.Value}");

Console.WriteLine();
Next();   // некуда — мы в конце
Back();   // habr → youtube
