//
// Created by Bohan Gao on 9/15/20.
//

#include <curl/curl.h>
#include <future>
#include <list>

#include "DownloadImagesDemo.h"

void DownloadImagesDemo::test() {
    const int NUM_IMAGES = 50;
    size_t parallel_result = parallelImageDownload(NUM_IMAGES);

    printf("Total image size is %lld", parallel_result);
}

size_t DownloadImagesDemo::parallelImageDownload(int num_images) {
    size_t total_bytes = 0;
    std::list<std::future<size_t>> download_futures;
    for (int i=1; i<=num_images; i++) {
        download_futures.push_back(std::async(std::launch::async, download, i));
    }
    for (int i=1; i<=num_images; i++) {
        total_bytes += download_futures.front().get();
        download_futures.pop_front();
    }
    return total_bytes;
}

size_t DownloadImagesDemo::download(int image_num) {
    char url[] = "http://699340.youcanlearnit.net/imageXXX.jpg";
    sprintf(url, "http://699340.youcanlearnit.net/image%03d.jpg", ((image_num % 50) + 1));

    CURLcode res;
    curl_off_t num_bytes = 0;
    CURL *curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        res = curl_easy_getinfo(curl, CURLINFO_SIZE_DOWNLOAD_T, &num_bytes);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_getinfo() failed: %s\n", curl_easy_strerror(res));
        }
        curl_easy_cleanup(curl);
    }
    return num_bytes;
}

size_t
DownloadImagesDemo::writeCallback(void *contents, size_t size, size_t nmemb,
                                  void *userp) {
    return size * nmemb;
}
