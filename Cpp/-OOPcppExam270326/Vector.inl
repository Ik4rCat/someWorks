

template <typename T>
Vector<T>::Vector() : data(nullptr), size(0) {}

template <typename T>
Vector<T>::Vector(size_t n) : size(n) {
    if (n > 0) {
        data = new T[n]();
    } else {
        data = nullptr;
    }
}

template <typename T>
Vector<T>::Vector(std::initializer_list<T> list) : size(list.size()) {
    if (size > 0) {
        data = new T[size];
        size_t count = 0;
        for (const auto& val : list) {
            data[count++] = val;
        }
    } else {
        data = nullptr;
    }
}

template <typename T>
Vector<T>::Vector(const Vector& other) : size(other.size) {
    if (size > 0) {
        data = new T[size];
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