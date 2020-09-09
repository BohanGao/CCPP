//
// Created by Bohan Gao on 9/8/20.
//

#ifndef CONCURRENCY_DETACHEDTHREADDEMO_H
#define CONCURRENCY_DETACHEDTHREADDEMO_H


class DetachedThreadDemo {
public:
    static void testWithoutDetaching();

    static void testWithDetaching();

private:
    static void clean_kitchen();
};


#endif //CONCURRENCY_DETACHEDTHREADDEMO_H
