#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include "base64.h"

#pragma comment(lib,"libssl.lib")
#pragma comment(lib,"libcrypto.lib")

using namespace std;

// 私钥加密
std::string rsa_pri_encrypt(const std::string& clearText, std::string& pubKey)
{
    std::string strRet;
    BIO* keybio = BIO_new_mem_buf((unsigned char*)pubKey.c_str(), -1);

    RSA* rsa = RSA_new();
    rsa = PEM_read_bio_RSAPrivateKey(keybio, &rsa, NULL, NULL);
    if (!rsa)
    {
        BIO_free_all(keybio);
        return std::string("");
    }

    int len = RSA_size(rsa);
    char* encryptedText = (char*)malloc(len + 1);
    memset(encryptedText, 0, len + 1);

    // 加密
    int ret = RSA_private_encrypt(clearText.length(), (const unsigned char*)clearText.c_str(), (unsigned char*)encryptedText, rsa, RSA_PKCS1_PADDING);
    if (ret >= 0)
        strRet = std::string(encryptedText, ret);

    // 释放内存
    free(encryptedText);
    BIO_free_all(keybio);
    RSA_free(rsa);

    return strRet;
}

// 公钥解密
std::string rsa_pub_decrypt(const std::string& clearText, std::string& pubKey)
{
    std::string strRet;
    BIO* keybio = BIO_new_mem_buf((unsigned char*)pubKey.c_str(), -1);
    RSA* rsa = RSA_new();

    //rsa = PEM_read_bio_RSAPublicKey(keybio, &rsa, NULL, NULL);//这个失败，二脸萌壁...
    rsa = PEM_read_bio_RSA_PUBKEY(keybio, &rsa, NULL, NULL);
    if (!rsa)
    {

        BIO_free_all(keybio);
        return std::string("");
    }

    int len = RSA_size(rsa);
    char* encryptedText = (char*)malloc(len + 1);
    memset(encryptedText, 0, len + 1);

    //解密
    int ret = RSA_public_decrypt(clearText.length(), (const unsigned char*)clearText.c_str(), (unsigned char*)encryptedText, rsa, RSA_PKCS1_PADDING);

    if (ret >= 0)
        strRet = std::string(encryptedText, ret);

    // 释放内存
    free(encryptedText);
    BIO_free_all(keybio);
    RSA_free(rsa);

    return strRet;
}
char* Base64Encode(const char* input, int length, bool with_new_line)
{
    BIO* bmem = NULL;
    BIO* b64 = NULL;
    BUF_MEM* bptr = NULL;
    b64 = BIO_new(BIO_f_base64());
    if (!with_new_line)
    {
        BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL);
    }
    bmem = BIO_new(BIO_s_mem());
    b64 = BIO_push(b64, bmem);
    BIO_write(b64, input, length);
    BIO_flush(b64);
    BIO_get_mem_ptr(b64, &bptr);
    char* buff = (char*)malloc(bptr->length + 1);
    memcpy(buff, bptr->data, bptr->length);
    buff[bptr->length] = 0;
    BIO_free_all(b64);
    return buff;
}
char* Base64Decode(char* input, int length, bool with_new_line)
{
    BIO* b64 = NULL;
    BIO* bmem = NULL;
    char* buffer = (char*)malloc(length);
    memset(buffer, 0, length);
    b64 = BIO_new(BIO_f_base64());
    if (!with_new_line)
    {
        BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL);
    }
    bmem = BIO_new_mem_buf(input, length);
    bmem = BIO_push(b64, bmem);
    BIO_read(bmem, buffer, length);
    BIO_free_all(bmem);
    return buffer;
}

// 公钥加密
std::string rsa_pub_encrypt(const std::string& clearText, std::string& pubKey)
{
    std::string strRet;
    BIO* keybio = BIO_new_mem_buf((unsigned char*)pubKey.c_str(), -1);
    RSA* rsa = RSA_new();


    //rsa = PEM_read_bio_RSAPublicKey(keybio, &rsa, NULL, NULL);//这个失败，二脸萌壁..
    rsa = PEM_read_bio_RSA_PUBKEY(keybio, &rsa, NULL, NULL);
    if (!rsa)
    {
        BIO_free_all(keybio);
        return std::string("");
    }

    int len = RSA_size(rsa);
    char* encryptedText = (char*)malloc(len + 1);
    memset(encryptedText, 0, len + 1);

    // 加密函数
    int ret = RSA_public_encrypt(clearText.length(), (const unsigned char*)clearText.c_str(), (unsigned char*)encryptedText, rsa, RSA_PKCS1_PADDING);
    if (ret >= 0)
        strRet = std::string(encryptedText, ret);

    // 释放内存
    free(encryptedText);
    BIO_free_all(keybio);
    RSA_free(rsa);

    return strRet;
}

// 私钥解密
std::string rsa_pri_decrypt(const std::string& cipherText, const std::string& priKey)
{
    std::string strRet;
    RSA* rsa = RSA_new();
    BIO* keybio;
    keybio = BIO_new_mem_buf((unsigned char*)priKey.c_str(), -1);

    rsa = PEM_read_bio_RSAPrivateKey(keybio, &rsa, NULL, NULL);

    int len = RSA_size(rsa);
    char* decryptedText = (char*)malloc(len + 1);
    memset(decryptedText, 0, len + 1);

    // 解密函数
    int ret = RSA_private_decrypt(cipherText.length(), (const unsigned char*)cipherText.c_str(), (unsigned char*)decryptedText, rsa, RSA_PKCS1_PADDING);
    if (ret >= 0)
        strRet = std::string(decryptedText, ret);

    // 释放内存
    free(decryptedText);
    BIO_free_all(keybio);
    RSA_free(rsa);
    return strRet;
}