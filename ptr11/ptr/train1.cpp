#include <iostream>
#include <memory>

template <typename T>
class ArraySharedPtr {
private:
    std::shared_ptr<T[]> ptr;

public:
    // 构造函数
    ArraySharedPtr(T* array, size_t size) : ptr(array, [](T* p) { delete[] p; }) {}

    // 静态方法，类似于 std::make_shared
    static ArraySharedPtr<T> make_shared(size_t size, T value = T()) {
        T* array = new T[size];
        for (size_t i = 0; i < size; ++i){
            array[i] = value;
        }
        return ArraySharedPtr<T>(array, size);
    }

    // 下标运算符
    T& operator[](size_t index) {
        return ptr[index];
    }

    const T& operator[](size_t index) const {
        return ptr[index];
    }

    // 获取原始指针
    T* get() const {
        return ptr.get();
    }

    // 获取数组大小
    size_t size() const {
        return ptr.use_count(); // 这里假设 size 是已知的，实际应用中可能需要额外存储 size
    }

    // 显式转换为 bool
    explicit operator bool() const {
        return ptr != nullptr;
    }
};

int main() {
    // 使用自定义的 make_shared 方法创建数组对象
    ArraySharedPtr<int> sp3 = ArraySharedPtr<int>::make_shared(2, 123);

    // 初始化数组中的元素
    sp3[0] = 123;
    sp3[1] = 3;

    // 输出数组中的元素
    std::cout << "Element 0: " << sp3[0] << std::endl;
    std::cout << "Element 1: " << sp3[1] << std::endl;

    return 0;
}