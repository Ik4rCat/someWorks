def count_words(s: str) -> int:
    if not isinstance(s, str):
        raise TypeError("Input must be a string")
    return len(s.split())


def factorial(n: int) -> int:
    if isinstance(n, bool) or not isinstance(n, int):
        raise TypeError("Input must be an integer")
    if n < 0:
        raise ValueError("Factorial is not defined for negative numbers")
    result = 1
    for i in range(1, n + 1):
        result *= i
    return result


def is_strong_password(password: str) -> bool:
    if not isinstance(password, str):
        raise TypeError("Password must be a string")
    return (
        len(password) >= 8
        and any(c.isdigit() for c in password)
        and any(c.isupper() for c in password)
    )


def is_valid_email(email: str) -> bool:
    if not isinstance(email, str):
        raise TypeError("Email must be a string")
    if ' ' in email:
        return False
    parts = email.split('@')
    if len(parts) != 2:
        return False
    local, domain = parts
    if not local or not domain:
        return False
    dot_idx = domain.rfind('.')
    if dot_idx < 1 or dot_idx == len(domain) - 1:
        return False
    return True
