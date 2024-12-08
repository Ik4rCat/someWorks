import asyncio

async def async_timer(seconds_list):
    for seconds in sorted(seconds_list):
        await asyncio.sleep(seconds)
        print(f"Прошло {seconds} секунд!")


async def fetch_data_1():
    await asyncio.sleep(2)
    return "Данные 1"

async def fetch_data_2():
    await asyncio.sleep(3)
    return "Данные 2"

async def fetch_data_3():
    await asyncio.sleep(1)
    return "Данные 3"

async def fetch_all():
    results = await asyncio.gather(fetch_data_1(), fetch_data_2(), fetch_data_3())
    print(f"Результаты: {results}")


async def progress_tracker(n):
    for i in range(1, n + 1):
        await asyncio.sleep(0.5)
        print(f"Выполнено {i * 10}%...")
    print("Выполнено 100%!")


async def process_task(queue):
    while not queue.empty():
        task = await queue.get()
        print(f"Обрабатываю: {task}")
        await asyncio.sleep(1)
        queue.task_done()

async def main_task_handler():
    queue = asyncio.Queue()
    for i in range(1, 6):
        await queue.put(f"Задача {i}")
    await asyncio.gather(process_task(queue), process_task(queue))
    await queue.join()


async def add_customers(queue):
    for i in range(1, 11):
        await queue.put(f"Покупатель {i}")
        print(f"Добавлен в очередь: Покупатель {i}")
        await asyncio.sleep(1)

async def serve_customers(queue):
    while not queue.empty():
        customer = await queue.get()
        print(f"Обслуживаю: {customer}")
        await asyncio.sleep(2)

async def main_shop():
    queue = asyncio.Queue()
    await asyncio.gather(add_customers(queue), serve_customers(queue))


async def producer(name, queue):
    for i in range(1, 11):
        await queue.put(i)
        print(f"{name}: сгенерировал {i}")
        await asyncio.sleep(1)

async def worker(task_queue, result_queue):
    while not task_queue.empty():
        data = await task_queue.get()
        result = data * 2
        print(f"Работник: обработал {data} -> {result}")
        await result_queue.put(result)
        await asyncio.sleep(1.5)
        task_queue.task_done()

async def saver(result_queue):
    saved_results = []
    while not result_queue.empty() or not task_queue.empty():
        if not result_queue.empty():
            data = await result_queue.get()
            saved_results.append(data)
            print(f"Сохранено: {saved_results}")
        await asyncio.sleep(2)

async def main_data_system():
    task_queue = asyncio.Queue()
    result_queue = asyncio.Queue()

    producers = [producer(f"Производитель {i+1}", task_queue) for i in range(3)]
    workers = [worker(task_queue, result_queue) for _ in range(2)]
    save = saver(result_queue)

    await asyncio.gather(*producers, *workers, save)


async def main():
    await async_timer([1, 3, 2])
    await fetch_all()
    await progress_tracker(10)
    await main_task_handler()
    await main_shop()
    await main_data_system()

asyncio.run(main())