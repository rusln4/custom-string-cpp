#include "../string.hpp"

#include <cstring>

String::String() {
  size_ = 0;
  capacity_ = 0;
  data_ = new char[1];
  data_[0] = '\0';
}

String::String(const char* str) {
  size_ = std::strlen(str);
  capacity_ = size_;
  data_ = new char[capacity_ + 1];
  std::memcpy(data_, str, size_ + 1);
}

String::String(size_t n, char c) {
  size_ = n;
  capacity_ = n;
  data_ = new char[capacity_ + 1];
  std::memset(data_, c, n);
  data_[n] = '\0';
}

String::String(const String& str) {
  size_ = str.size_;
  capacity_ = str.capacity_;
  data_ = new char[capacity_ + 1];
  std::memcpy(data_, str.data_, size_ + 1);
}

String::~String() {
  delete[] data_;
}

String& String::operator=(const String& str) {
  if (this == &str) {
    return *this;
  }
  if (capacity_ < str.size_) {
    char* new_data = new char[str.size_ + 1];
    std::memcpy(new_data, str.data_, str.size_ + 1);
    delete[] data_;
    data_ = new_data;
    capacity_ = str.size_;
  } else {
    std::memcpy(data_, str.data_, str.size_ + 1);
  }
  size_ = str.size_;
  return *this;
}

String operator+(const String& a, const String& b) {
  String res(a);
  res += b;
  return res;
}

String operator+(char c, const String& str) {
  String res(1, c);
  res += str;
  return res;
}

String operator+(const String& str, char c) {
  String res(str);
  res.PushBack(c);
  return res;
}

String& String::operator+=(const String& str) {
  size_t new_size = size_ + str.size_;
  if (capacity_ < new_size) {
    char* new_data = new char[new_size + 1];
    std::memcpy(new_data, data_, size_);
    std::memcpy(new_data + size_, str.data_, str.size_);
    delete[] data_;
    data_ = new_data;
    capacity_ = new_size;
  } else {
    std::memcpy(data_ + size_, str.data_, str.size_);
  }
  size_ = new_size;
  data_[size_] = '\0';
  return *this;
}

String& String::operator+=(char c) {
  PushBack(c);
  return *this;
}

char& String::operator[](size_t index) {
  return data_[index];
}

const char& String::operator[](size_t index) const {
  return data_[index];
}

bool String::operator==(const String& str) const {
  return size_ == str.size_ && std::memcmp(data_, str.data_, size_) == 0;
}

bool String::operator<(const String& str) const {
  size_t share_size = size_;
  if (str.size_ < size_) {
    share_size = str.size_;
  }
  int ans = std::memcmp(data_, str.data_, share_size);
  if (ans < 0) {
    return true;
  } else if (ans > 0) {
    return false;
  }
  return size_ < str.size_;
}

bool String::operator>(const String& str) const {
  size_t share_size = size_;
  if (str.size_ < size_) {
    share_size = str.size_;
  }
  int ans = std::memcmp(data_, str.data_, share_size);
  if (ans > 0) {
    return true;
  } else if (ans < 0) {
    return false;
  }
  return size_ > str.size_;
}

bool String::operator<=(const String& str) const {
  size_t share_size = size_;
  if (str.size_ < size_) {
    share_size = str.size_;
  }
  int ans = std::memcmp(data_, str.data_, share_size);
  if (ans < 0) {
    return true;
  } else if (ans > 0) {
    return false;
  }
  return size_ <= str.size_;
}

bool String::operator>=(const String& str) const {
  size_t share_size = size_;
  if (str.size_ < size_) {
    share_size = str.size_;
  }
  int ans = std::memcmp(data_, str.data_, share_size);
  if (ans > 0) {
    return true;
  } else if (ans < 0) {
    return false;
  }
  return size_ >= str.size_;
}

size_t String::Length() const {
  return size_;
}

size_t String::Size() const {
  return size_;
}

size_t String::Capacity() const {
  return capacity_;
}

size_t String::Find(const String& str) const {
  if (str.size_ > size_) {
    return Length();
  }
  for (size_t i = 0; i <= size_ - str.size_; ++i) {
    if (std::memcmp(data_ + i, str.data_, str.size_) == 0) {
      return i;
    }
  }
  return size_;
}

size_t String::Rfind(const String& str) const {
  if (str.size_ > size_) {
    return Length();
  }
  for (size_t i = size_ - str.size_ + 1; i > 0; --i) {
    if (std::memcmp(data_ + i - 1, str.data_, str.size_) == 0) {
      return i - 1;
    }
  }
  return size_;
}

bool String::Empty() const {
  return size_ == 0;
}

void String::Clear() {
  size_ = 0;
  data_[0] = '\0';
}

char* String::Data() {
  return data_;
}

const char* String::Data() const {
  return data_;
}

char& String::Front() {
  return data_[0];
}

const char& String::Front() const {
  return data_[0];
}

char& String::Back() {
  return data_[size_ - 1];
}

const char& String::Back() const {
  return data_[size_ - 1];
}

void String::PushBack(char c) {
  if (capacity_ == size_) {
    size_t new_capacity = 0;
    if (capacity_ == 0) {
      new_capacity = 1;
    } else {
      new_capacity = capacity_ * 2;
    }
    char* new_data = new char[new_capacity + 1];
    std::memcpy(new_data, data_, size_ + 1);
    delete[] data_;
    data_ = new_data;
    capacity_ = new_capacity;
  }
  data_[size_] = c;
  size_++;
  data_[size_] = '\0';
}

void String::PopBack() {
  if (size_ > 0) {
    size_--;
    data_[size_] = '\0';
  }
}

void String::ShrinkToFit() {
  if (capacity_ > size_) {
    char* new_data = new char[size_ + 1];
    std::memcpy(new_data, data_, size_ + 1);
    delete[] data_;
    data_ = new_data;
    capacity_ = size_;
  }
}

String String::Substr(size_t start, size_t count) const {
  if (start >= size_) {
    return String();
  }
  if (count > size_ - start) {
    count = size_ - start;
  }
  String str(count, '\0');
  std::memcpy(str.data_, data_ + start, count);
  return str;
}

std::ostream& operator<<(std::ostream& out, const String& str) {
  out.write(str.Data(), str.Size());
  return out;
}

std::istream& operator>>(std::istream& in, String& str) {
  in >> std::ws;
  str.Clear();
  char c;
  while (in.get(c)) {
    if (c == ' ' || c == '\n' || c == '\t') {
      break;
    }
    str.PushBack(c);
  }
  return in;
}

bool operator<(const char* a, const String& b) {
  return String(a) < b;
}

bool operator>(const char* a, const String& b) {
  return String(a) > b;
}
