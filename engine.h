#ifndef __ENGINE_H
#define __ENGINE_H
#include <openssl/md5.h>
#include <openssl/crypto.h>
#include <openssl/ssl.h>
#include <openssl/ssl23.h>
#include <openssl/ssl2.h>
#include <openssl/err.h>

#define SERV_CERT_PATH  256
#define SERV_PKEY_PATH  256

struct uvssl_sctx{
    char            cert_path[SERV_CERT_PATH];
    char            pkey_path[SERV_PKEY_PATH];
    SSL_CTX         *ctx;
    SSL             *ssl;
    SSL_METHOD      *method;
    int             fd;
};
struct uvssl_cctx{
    struct sockaddr_in  addr;
    SSL             *ssl;
};

#endif
