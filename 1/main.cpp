#include <UnitTest++/UnitTest++.h>
#include "/home/stud/C++Projects/Lab/2/modAlphaCipher.cpp"
#include "/home/stud/C++Projects/Lab/2/modAlphaCipher.h"
SUITE(KeyTest)
{
    TEST(ValidKey1) {
        modAlphaCipher test(L"Ниссан");
        CHECK(true);
    }
    TEST(ValidKey2) {
        modAlphaCipher test(L"НИССАН");
        CHECK(true);
    }
    TEST(EmptyKey) {
        CHECK_THROW(modAlphaCipher test(L""), cipher_error);
    }
    TEST(InvalidKey1) {
        CHECK_THROW(modAlphaCipher test(L"Нисс ан"), cipher_error);
    }
    TEST(InvalidKey2) {
        CHECK_THROW(modAlphaCipher test(L"2ниссана"), cipher_error);
    }
    TEST(InvalidKey3) {
        CHECK_THROW(modAlphaCipher test(L"ниссан!"), cipher_error);
    }
}
SUITE(EncryptTest)
{
    TEST(ValidText1) {
        wstring open_text = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
        wstring result_correct = L"АГВЕДЖЁИЗКЙМЛОНРПТСФУЦХШЧЪЩЬЫЮЭАЯ";
        CHECK_EQUAL(true, result_correct == modAlphaCipher(L"АВ").encrypt(open_text));
    }
    TEST(ValidText2) {
        wstring open_text = L"абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
        wstring result_correct = L"АГВЕДЖЁИЗКЙМЛОНРПТСФУЦХШЧЪЩЬЫЮЭАЯ";
        CHECK_EQUAL(true, result_correct == modAlphaCipher(L"АВ").encrypt(open_text));
    }
    TEST(EmptyText) {
        wstring open_text = L"";
        CHECK_THROW(modAlphaCipher(L"АВ").decrypt(open_text),cipher_error);
    }
    TEST(InvalidText1) {
        wstring open_text = L"Нисс ан";
        CHECK_THROW(modAlphaCipher(L"АВ").encrypt(open_text),cipher_error);
    }
    TEST(InvalidText2) {
        wstring open_text = L"2ниссана";
        CHECK_THROW(modAlphaCipher(L"АВ").encrypt(open_text),cipher_error);
    }
    TEST(InvalidText3) {
        wstring open_text = L"ниссан!";
        CHECK_THROW(modAlphaCipher(L"АВ").encrypt(open_text),cipher_error);
    }
}
SUITE(DecryptTest)
{
    TEST(ValidText1) {
        wstring cipher_text = L"АГВЕДЖЁИЗКЙМЛОНРПТСФУЦХШЧЪЩЬЫЮЭАЯ";
        wstring result_correct = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
        CHECK_EQUAL(true, result_correct == modAlphaCipher(L"АВ").decrypt(cipher_text));
    }
    TEST(ValidText2) {
        wstring cipher_text = L"агведжёизкймлонрптсфуцхшчъщьыюэая";
        wstring result_correct = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
        CHECK_EQUAL(true, result_correct == modAlphaCipher(L"АВ").decrypt(cipher_text));
    }
    TEST(EmptyText) {
        wstring cipher_text = L"";
        CHECK_THROW(modAlphaCipher(L"АВ").decrypt(cipher_text),cipher_error);
    }
    TEST(InvalidText1) {
        wstring cipher_text = L"Нисс ан";
        CHECK_THROW(modAlphaCipher(L"АВ").decrypt(cipher_text),cipher_error);
    }
    TEST(InvalidText2) {
        wstring cipher_text = L"2ниссана";
        CHECK_THROW(modAlphaCipher(L"АВ").decrypt(cipher_text),cipher_error);
    }
    TEST(InvalidText3 ) {
        wstring cipher_text = L"ниссан!";
        CHECK_THROW(modAlphaCipher(L"АВ").decrypt(cipher_text),cipher_error);
    }
}
int main()
{
    return UnitTest::RunAllTests();
}
