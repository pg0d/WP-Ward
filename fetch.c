
#include "common.h"
#include <curl/curl.h>
#include <curl/easy.h>

size_t write_callback(void *ptr, size_t size, size_t nmemb, void *userdata);

int perform_http_get(const char *url, char *response_buffer, size_t buffer_size)
{
    CURL *curl;
    CURLcode res;

    int result = 0;
    
    curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "Failed to initialize cURL.\n");
        return -1;
    }

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, response_buffer);

    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        fprintf(stderr, "cURL request failed: %s\n", curl_easy_strerror(res));
        result = -1;
    }

    curl_easy_cleanup(curl);
    return result;
}

size_t write_callback(void *ptr, size_t size, size_t nmemb, void *userdata) {
    size_t total_size = size * nmemb;
    char *response_buffer = (char *)userdata;

    strncat(response_buffer, (char *)ptr, total_size);
    return total_size;
}
