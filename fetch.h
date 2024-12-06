#ifndef FETCH_H
#define FETCH_H

#include "common.h"

size_t write_callback(void *ptr, size_t size, size_t nmemb, void *userdata);
int perform_http_get(const char *url, char *response_buffer, size_t buffer_size);

#endif
