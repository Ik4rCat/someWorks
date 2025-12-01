class LoggingManager:
    
    def log(func):
        loglist = []
        def wrapper(username, *args):
            loglist.append(f"Вызов функции {func.__name__} пользователем {username} с аргументами {args}")
            return func(username, *args)
        return wrapper

taskList = []

while True:
    usinput = input("""
    1. Add task in list
    2. Watch task list
    3. Change task status 
    0. Exit programm
                    
    Credits - made by alt

    write: """)
    
    if usinput == 1:
        new_task = input("[!] New task: ")
        taskList.append(new_task)
    elif usinput == 2:
        print(f"task list: {taskList}")

        
    elif usinput == 0:
        break 