#ifndef __UTILS_H
#define __UTILS_H

#include <openssl/md5.h>
#include <openssl/crypto.h>
#include <openssl/ssl.h>
#include <openssl/ssl23.h>
#include <openssl/ssl2.h>
#include <openssl/err.h>
int read_proc(char *proc, char *buf, int len);
void print_cert(SSL* ssl);
#endif
