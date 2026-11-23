
#include "../string.hpp"

#include <gtest/gtest.h>

TEST(String, NullString) {
  String str;
  ASSERT_EQ(0, str.Size());
  ASSERT_EQ(0, str.Length());
  ASSERT_EQ(0, str.Capacity());
  ASSERT_EQ('\0', str.Data()[0]);
}

TEST(String, DefaultConstructor) {
  String str;
  ASSERT_EQ(0, str.Size());
  ASSERT_EQ(0, str.Length());
  ASSERT_EQ(0, str.Capacity());
  ASSERT_TRUE(str.Empty());
  ASSERT_EQ('\0', str.Data()[0]);
}

TEST(String, FillConstructor) {
  String str(4, 'a');
  ASSERT_EQ(4, str.Size());
  ASSERT_EQ(4, str.Capacity());
  ASSERT_EQ('a', str[0]);
  ASSERT_EQ('a', str[1]);
  ASSERT_EQ('a', str[2]);
  ASSERT_EQ('a', str[3]);
  ASSERT_EQ('\0', str.Data()[4]);
}

TEST(String, CopyConstructor) {
  String a("hello");
  String b(a);
  ASSERT_TRUE(a == b);
  ASSERT_EQ(a.Size(), b.Size());
  ASSERT_NE(a.Data(), b.Data());
  b[0] = 'H';
  ASSERT_EQ('h', a[0]);
  ASSERT_EQ('H', b[0]);
}

TEST(String, PushBackPopBack) {
  String str;
  str.PushBack('a');
  str.PushBack('b');
  str.PushBack('c');
  ASSERT_EQ(3, str.Size());
  ASSERT_EQ('a', str[0]);
  ASSERT_EQ('b', str[1]);
  ASSERT_EQ('c', str[2]);
  ASSERT_EQ('\0', str.Data()[3]);
  str.PopBack();
  ASSERT_EQ(2, str.Size());
  ASSERT_EQ('b', str.Back());
  ASSERT_EQ('\0', str.Data()[2]);
}

TEST(String, Compare) {
  String a("apple");
  String b("banana");
  String c("apple");
  ASSERT_TRUE(a == c);
  ASSERT_FALSE(a == b);
  ASSERT_TRUE(a < b);
  ASSERT_TRUE(b > a);
  ASSERT_TRUE(a <= c);
  ASSERT_TRUE(a >= c);
  ASSERT_FALSE(a > b);
  ASSERT_FALSE(b < a);
}
