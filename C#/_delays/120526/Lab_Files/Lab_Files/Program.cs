using System.Text;

// ══════════════════════════════════════════════════════════════════
//  Задание 1 — «Аналитик логов»: StreamReader / StreamWriter
// ══════════════════════════════════════════════════════════════════

Console.WriteLine("=== Задание 1: Фильтрация лога ===\n");

const string logFile    = "access.log";
const string outputFile = "errors_only.txt";

// Генерируем тестовый файл, если его нет
if (!File.Exists(logFile))
{
    using var gen = new StreamWriter(logFile, false, Encoding.UTF8);
    var lines = new[]
    {
        "[2023-10-10 12:00:00] INFO: Запрос обработан успешно",
        "[2023-10-10 12:00:01] ERROR: Сбой соединения",
        "[2023-10-10 12:00:02] INFO: Пользователь вошёл в систему",
        "[2023-10-10 12:00:03] ERROR: Таймаут запроса к БД",
        "[2023-10-10 12:00:04] WARNING: Низкое место на диске",
        "[2023-10-10 12:00:05] ERROR: Неверный токен авторизации",
        "[2023-10-10 12:00:06] INFO: Кэш очищен",
        "[2023-10-10 12:00:07] ERROR: Сервис недоступен",
    };
    foreach (var l in lines) gen.WriteLine(l);
    Console.WriteLine($"  Создан тестовый файл: {logFile}");
}

// Читаем построчно — StreamReader не грузит весь файл в память
int errorCount = 0;
using (var reader = new StreamReader(logFile, Encoding.UTF8))
using (var writer = new StreamWriter(outputFile, false, Encoding.UTF8))
{
    string? line;
    while ((line = reader.ReadLine()) != null)
    {
        if (line.Contains("ERROR"))
        {
            writer.WriteLine(line);
            errorCount++;
        }
    }
}

Console.WriteLine($"  Готово. Найдено ошибок: {errorCount}");
Console.WriteLine($"  Результат записан в: {outputFile}\n");

Console.WriteLine(new string('═', 60));
Console.WriteLine();

// ══════════════════════════════════════════════════════════════════
//  Задание 2 — «Конвертер кодировок»: Windows-1251 → UTF-8
// ══════════════════════════════════════════════════════════════════

Console.WriteLine("=== Задание 2: Конвертер кодировок ===\n");

const string srcFile = "source_1251.txt";
const string dstFile = "result_utf8.txt";

// Нужно зарегистрировать провайдер, чтобы .NET дал нам CP1251
Encoding.RegisterProvider(CodePagesEncodingProvider.Instance);
var enc1251 = Encoding.GetEncoding(1251);

// Создаём тестовый файл в Windows-1251, если нет
if (!File.Exists(srcFile))
{
    File.WriteAllText(srcFile, "Привет мир\nэто старый файл в cp1251\nтут кириллица", enc1251);
    Console.WriteLine($"  Создан тестовый файл в CP1251: {srcFile}");
}

// Читаем в CP1251
string content = File.ReadAllText(srcFile, enc1251);

// Модифицируем: верхний регистр + дата в начале
string modified = $"[Конвертировано: {DateTime.Now:yyyy-MM-dd HH:mm:ss}]\n{content.ToUpper()}";

// Сохраняем в UTF-8
File.WriteAllText(dstFile, modified, Encoding.UTF8);

Console.WriteLine($"  Прочитан файл в CP1251. Исходное содержимое:");
foreach (var l in content.Split('\n'))
    Console.WriteLine($"    {l}");
Console.WriteLine($"\n  Сохранено в UTF-8: {dstFile}");
Console.WriteLine($"  Первые строки результата:");
foreach (var l in modified.Split('\n').Take(3))
    Console.WriteLine($"    {l}");

Console.WriteLine();
Console.WriteLine(new string('═', 60));
Console.WriteLine();

// ══════════════════════════════════════════════════════════════════
//  Задание 3 — «Сейв-менеджер»: BinaryWriter / BinaryReader
// ══════════════════════════════════════════════════════════════════

Console.WriteLine("=== Задание 3: Сейв-менеджер игрока ===\n");

const string saveFile = "save.dat";

// Данные персонажа
string  playerName  = "Котолаз";
int     playerLevel = 42;
double  playerHp    = 87.5;
byte[]  inventory   = { 12, 7, 255, 3, 0, 99 }; // координаты/ID предметов

// ── Запись ──────────────────────────────────────────────────────
using (var bw = new BinaryWriter(File.Create(saveFile)))
{
    bw.Write(playerName);           // string (с длиной-префиксом)
    bw.Write(playerLevel);          // int    (4 байта)
    bw.Write(playerHp);             // double (8 байт)
    bw.Write(inventory.Length);     // int    — сначала длина массива
    bw.Write(inventory);            // byte[] — затем сами байты
}

Console.WriteLine($"  Сохранено в {saveFile} ({new FileInfo(saveFile).Length} байт)");
Console.WriteLine("  (Открой файл в текстовом редакторе — там будет нечитаемый бинарник)\n");

// ── Чтение ──────────────────────────────────────────────────────
string  loadedName;
int     loadedLevel;
double  loadedHp;
byte[]  loadedInventory;

using (var br = new BinaryReader(File.OpenRead(saveFile)))
{
    loadedName      = br.ReadString();
    loadedLevel     = br.ReadInt32();
    loadedHp        = br.ReadDouble();
    int len         = br.ReadInt32();
    loadedInventory = br.ReadBytes(len);
}

Console.WriteLine("  Загружено из файла:");
Console.WriteLine($"    Имя:       {loadedName}   (тип: {loadedName.GetType().Name})");
Console.WriteLine($"    Уровень:   {loadedLevel}    (тип: {loadedLevel.GetType().Name})");
Console.WriteLine($"    HP:        {loadedHp}   (тип: {loadedHp.GetType().Name})");
Console.WriteLine($"    Инвентарь: [{string.Join(", ", loadedInventory)}]  (тип: {loadedInventory.GetType().Name})");

Console.WriteLine();
Console.WriteLine("  Типы восстановлены корректно: double остался double, int остался int.");
