#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
int read_proc(char *proc, char *buf, int len)
{
    int ret = -1;
    if(!proc || !buf) return -1;
    FILE *fp = NULL;
    fp = fopen(proc, "r");
    if(fp) {
        if(fgets(buf, len, fp) != NULL) {
            ret = 0;
        }
        fclose(fp);
    }
    return ret;
}
void print_cert(SSL* ssl)
{
    X509 *cert;
    char *line;

    cert = SSL_get_peer_certificate(ssl); /* Get certificates (if available) */
    if ( cert != NULL )
    {
        printf("Certificates:\n");
        line = X509_NAME_oneline(X509_get_subject_name(cert), 0, 0);
        printf("Subject: %s\n", line);
        free(line);
        line = X509_NAME_oneline(X509_get_issuer_name(cert), 0, 0);
        printf("Issuer: %s\n", line);
        free(line);
        X509_free(cert);
    }else{
        printf("No certificates.\n");
    }
}
