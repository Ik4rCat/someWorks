import re


def is_palindrome(s: str) -> bool:
    cleaned = re.sub(r'[^a-zA-Zа-яА-ЯёЁ0-9]', '', s).lower()
    return cleaned == cleaned[::-1]
