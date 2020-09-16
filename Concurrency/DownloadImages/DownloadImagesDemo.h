//
// Created by Bohan Gao on 9/15/20.
//

#ifndef CONCURRENCY_DOWNLOADIMAGESDEMO_H
#define CONCURRENCY_DOWNLOADIMAGESDEMO_H


class DownloadImagesDemo {
public:
    static void test();

private:
    static size_t parallelImageDownload(int num_images);

    static size_t download(int image_num);

    static size_t writeCallback(void *contents, size_t size, size_t nmemb, void *userp);
};


#endif //CONCURRENCY_DOWNLOADIMAGESDEMO_H
