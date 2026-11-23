#include <iostream>

class String {
 public:
  String();
  String(const char* str);
  String(size_t n, char c);
  String(const String& str);

  ~String();

  String& operator=(const String& str);
  String& operator+=(const String& str);
  String& operator+=(const char c);
  char& operator[](size_t index);
  const char& operator[](size_t index) const;
  bool operator==(const String& str) const;
  bool operator<(const String& str) const;
  bool operator>(const String& str) const;
  bool operator<=(const String& str) const;
  bool operator>=(const String& str) const;

  size_t Length() const;
  size_t Size() const;
  size_t Capacity() const;
  bool Empty() const;
  void Clear();
  char* Data();
  const char* Data() const;
  char& Front();
  const char& Front() const;
  char& Back();
  const char& Back() const;
  void PushBack(char c);
  void PopBack();
  void ShrinkToFit();
  size_t Find(const String& str) const;
  size_t Rfind(const String& str) const;
  String Substr(size_t start, size_t count) const;

 private:
  char* data_;
  size_t size_;
  size_t capacity_;
};

String operator+(const String& a, const String& b);
String operator+(const String& str, char c);
String operator+(char c, const String& str);
std::ostream& operator<<(std::ostream& out, const String& str);
std::istream& operator>>(std::istream& in, String& str);

bool operator<(const char* a, const String& b);
bool operator>(const char* a, const String& b);