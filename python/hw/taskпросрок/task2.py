from functools import total_ordering

@total_ordering
class RealString:
    def __init__(self, string):
        self.string = str(string)

    def __eq__(self, other):
        if isinstance(other, RealString):
            return len(self.string) == len(other.string)
        return len(self.string) == len(str(other))

    def __lt__(self, other):
        if isinstance(other, RealString):
            return len(self.string) < len(other.string)
        return len(self.string) < len(str(other))
    
    def __str__(self):
        return self.string

def main():
    print("Write '0' to exit program")
    
    while True:
        print("\n" + "="*40)
        str1 = input("Write first string: ")
        
        if str1 == '0':
            print("Exit program...")
            break
            
        str2 = input("Write second string: ")
        
        if str2 == '0':
            print("Exit program...")
            break
        
        rs1 = RealString(str1)
        rs2 = RealString(str2)
        
        print(f"\nResults:")
        print(f"'{rs1}' == '{rs2}': {rs1 == rs2}")
        print(f"'{rs1}' != '{rs2}': {rs1 != rs2}")
        print(f"'{rs1}' < '{rs2}': {rs1 < rs2}")
        print(f"'{rs1}' > '{rs2}': {rs1 > rs2}")
        print(f"'{rs1}' <= '{rs2}': {rs1 <= rs2}")
        print(f"'{rs1}' >= '{rs2}': {rs1 >= rs2}")
        
        print(f"\nLenth '{rs1}': {len(rs1.string)}")
        print(f"Lenth '{rs2}': {len(rs2.string)}")


main()