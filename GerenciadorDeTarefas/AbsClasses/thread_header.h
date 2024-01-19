#ifndef THREAD_HEADER_H
#define THREAD_HEADER_H

#include <QObject>

class ThreadHeader : public QObject {
    Q_OBJECT

public:
    virtual ~ThreadHeader() = default;
    virtual void run() = 0;
    virtual void init() = 0;
    virtual void close() = 0;
    virtual void await() = 0;
};

#endif // THREAD_HEADER_H
