#include <UnitTest++/UnitTest++.h>
#include "/home/stud/C++Projects/Laboratornye/lab_2/lab_2_1/Cipher.h"
#include "/home/stud/C++Projects/Laboratornye/lab_2/lab_2_1/Cipher.cpp"
SUITE(KeyTest)
{
    TEST(ValidKey) {
        CHECK_EQUAL("OWOLLDELHR", Cipher().cipher("HELLOWORLD",7));
    }
    TEST(EmptyKey) {
        CHECK_THROW(Cipher().cipher("HELLOWORLD", 0),cipher_error);
    }
    TEST(InvalidKey1) {
        CHECK_THROW(Cipher().cipher("HELLOWORLD", 1),cipher_error);
    }
    TEST(InvalidKey2) {
        CHECK_THROW(Cipher().cipher("HELLOWORLD", -5),cipher_error);
    }
}
SUITE(CipherTest)
{
    TEST(ValidText1) {
        CHECK_EQUAL("LRLOEWDHOL", Cipher().cipher("HELLOWORLD",4));
    }
    TEST(ValidText2) {
        CHECK_EQUAL("lrloewdHol", Cipher().cipher("Helloworld",4));
    }
    TEST(EmptyText) {
        CHECK_THROW(Cipher().cipher("",4),cipher_error);
    }
}
int main(int argc, char **argv)
{
    return UnitTest::RunAllTests();
}
