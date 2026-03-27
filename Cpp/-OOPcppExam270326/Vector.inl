

template <typename T>
Vector<T>::Vector() : data(nullptr), size_(0) {}

template <typename T>
Vector<T>::Vector(size_t n) : data(nullptr), size_(n) {
    data = (size_ > 0) ? new T[size_]() : nullptr;
}

template <typename T>
Vector<T>::Vector(std::initializer_list<T> list) : data(nullptr), size_(list.size()) {
    if (size_ > 0) {
        data = new T[size_];
        size_t count = 0;
        for (const auto& val : list) {
            data[count++] = val;
        }
    } else {
        data = nullptr;
    }
}

template <typename T>
Vector<T>::Vector(const Vector& other) : data(nullptr), size_(other.size_) {
    if (size_ > 0) {
        data = new T[size_];
        for (size_t i = 0; i < size_; ++i) {
            data[i] = other.data[i];
        }
    } else {
        data = nullptr;
    }
}

template <typename T>
Vector<T>::~Vector() {
    delete[] data;
}

template <typename T>
T& Vector<T>::operator[](size_t index) {
    return data[index];
}

template <typename T>
const T& Vector<T>::operator[](size_t index) const {
    return data[index];
}

template <typename T>
size_t Vector<T>::size() const {
    return size_;
}

template <typename T>
bool Vector<T>::empty() const {
    return size_ == 0;
}

template <typename T>
void Vector<T>::resize(size_t newSize) {
    T* newData = (newSize > 0) ? new T[newSize]() : nullptr;
    const size_t copyCount = (newSize < size_) ? newSize : size_;
    for (size_t i = 0; i < copyCount; ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    size_ = newSize;
}

template <typename T>
void Vector<T>::push(const T& value) {
    const size_t oldSize = size_;
    resize(size_ + 1);
    data[oldSize] = value;
}

template <typename T>
void Vector<T>::pop() {
    if (size_ == 0) {
        return;
    }
    resize(size_ - 1);
}

template <typename T>
void Vector<T>::insert(size_t index, const T& value) {
    if (index > size_) {
        return;
    }
    const size_t oldSize = size_;
    resize(size_ + 1);
    for (size_t i = oldSize; i > index; --i) {
        data[i] = data[i - 1];
    }
    data[index] = value;
}

template <typename T>
void Vector<T>::print() const {
    std::cout << "Vector elements:";
    for (size_t i = 0; i < size_; ++i) {
        std::cout << " " << data[i];
    }
    std::cout << std::endl;
}

template <typename Elem, typename I, typename D, typename L>
void calculateAndPrint(Vector<Elem>& vec, I i, D d, L l) {
    static_assert(std::is_same_v<std::decay_t<I>, int> &&
                  std::is_same_v<std::decay_t<D>, double> &&
                  std::is_same_v<std::decay_t<L>, long>,
                 "calculateAndPrint: разрешены только (int, double, long)");

    if (l == 0) {
        std::cout << -1 << std::endl;
        return;
    }

    const long double result =
        (static_cast<long double>(i) + static_cast<long double>(d)) / static_cast<long double>(l);

    if (result < 0) {
        std::cout << -1 << std::endl;
        return;
    }

    const size_t index = static_cast<size_t>(result);
    if (index < vec.size()) {
        std::cout << vec[index] << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }
}