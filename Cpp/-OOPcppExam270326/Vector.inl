

template <typename T>
Vector<T>::Vector() : data(nullptr), size(0), capacity(0) {}

template <typename T>
Vector<T>::Vector(size_t n) : data(nullptr), size(n), capacity(n) {
    if (capacity > 0) {
        data = new T[capacity]();
    } else {
        data = nullptr;
    }
}

template <typename T>
Vector<T>::Vector(std::initializer_list<T> list) : data(nullptr), size(list.size()), capacity(list.size()) {
    if (size > 0) {
        data = new T[capacity];
        size_t count = 0;
        for (const auto& val : list) {
            data[count++] = val;
        }
    } else {
        data = nullptr;
    }
}

template <typename T>
Vector<T>::Vector(const Vector& other) : data(nullptr), size(other.size), capacity(other.capacity) {
    if (capacity > 0) {
        data = new T[capacity];
        for (size_t i = 0; i < size; ++i) {
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
size_t Vector<T>::getCapacity() const {
    return capacity;
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
size_t Vector<T>::getSize() const {
    return size;
}

template <typename T>
bool Vector<T>::empty() const {
    return size == 0;
}

template <typename T>
void Vector<T>::resize(size_t newSize) {
    if (newSize <= capacity) {
        if (newSize > size) {
            for (size_t i = size; i < newSize; ++i) {
                data[i] = T();
            }
        }
        size = newSize;
        return;
    }

    size_t newCapacity = capacity == 0 ? 1 : capacity;
    while (newCapacity < newSize) {
        newCapacity *= 2;
    }

    T* newData = new T[newCapacity]();
    for (size_t i = 0; i < size; ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
    size = newSize;
}

template <typename T>
void Vector<T>::push(const T& value) {
    if (size == capacity) {
        resize(size + 1);
        data[size - 1] = value;
        return;
    }
    data[size++] = value;
}

template <typename T>
void Vector<T>::pop() {
    if (size == 0) {
        return;
    }
    --size;
}

template <typename T>
void Vector<T>::insert(size_t index, const T& value) {
    if (index > size) {
        return;
    }
    if (size == capacity) {
        resize(size + 1);
    } else {
        ++size;
    }
    for (size_t i = size - 1; i > index; --i) {
        data[i] = data[i - 1];
    }
    data[index] = value;
}

template <typename T>
void Vector<T>::print() const {
    std::cout << "Vector elements:";
    for (size_t i = 0; i < size; ++i) {
        std::cout << " " << data[i];
    }
    std::cout << std::endl;
}

template <>
inline void Vector<Point>::print() const {
    std::cout << "Number of points: " << size << std::endl;
}

template <typename T>
void calculateAndPrint(Vector<T>& vec, int i, double d, long l) {
    if (l == 0) {
        std::cout << -1 << std::endl;
        return;
    }
    double result = (static_cast<double>(i) + d) / static_cast<double>(l);
    size_t index = static_cast<size_t>(result);
    if (index < vec.getSize()) {
        std::cout << vec[index] << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }
}