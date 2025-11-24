import sys, os

def PrintSection(title: str):
    bar = "=" * len(title)
    print(f"\n{title}\n{bar}")

def SafeInput(prompt: str) -> str:
    try:
        return input(prompt)
    except Exception:
        return ""

#--------------Logging-part--------------#

def logTransactions(func):
    loglist = []
    def wrapper(username, *args):
        loglist.append(f"Вызов функции {func.__name__} с аргументами {args}")
        return func(username, *args)
    return wrapper

#----------Finance-manager-part----------#
class FinanceManager:
    def __init__(self):
        self.balance
        self.transactionList
        return

    @logTransactions
    def AddTransactions(self, type, amount, category):
        self.type = input("[type] Write type of transaction (income/expense): ") 
        self.amount = input("[amount] Write the amount of income/expenses: ")
        self.category = input("[category] Write category of transaction in one word (For example: food): ")
        return 
    
    @logTransactions
    def GetTransacions(self):
        return
    
    def GetBalance(self):
        return
    
    @logTransactions
    def SaveData(self):
        return
    
    @logTransactions
    def LoadData(self):
        return

    def Run(self):
        
        if len(sys.argv) > 1:
            start_dir = sys.argv[1]
            if os.path.isdir(start_dir):
                try:
                    os.chdir(start_dir)
                except Exception:
                    pass

        while True:
            PrintSection("Main menu: welcome to Finance Manager")
            print("""
                1) Watch balance and transactions >>
                2) Add your income/consumption >>
                0) Save and exit >>
                """)

            sel = SafeInput("[?] Choice: ").strip()

            if sel == "1":
                FinanceManager
            elif sel == "2":
                FinanceManager.AddTransactions()
            elif sel == "0":
                FinanceManager.SaveData()
                print("[i] Saving & Exiting.")
                break
            else:
                print("[!] Unknown menu item.")
