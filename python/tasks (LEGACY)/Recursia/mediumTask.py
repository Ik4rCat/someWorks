sampleWord1 = "abc"
sampleWord2 = "abba"
userWord = ""

def IsParalindrome(word):
    if word == reversed(word):
        print("true")
    else:
        print("false")

def main():
    print(f"""
    {IsParalindrome(sampleWord1)}
    {IsParalindrome(sampleWord2)}
    """)

    userInp = input("\n write a word: ")
    IsParalindrome(userInp)

main()