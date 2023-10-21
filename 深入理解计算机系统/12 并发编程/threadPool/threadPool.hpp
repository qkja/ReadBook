#ifndef __THREADPOOL_HPP__
#define __THREADPOOL_HPP__
#include <queue>
#include <assert.h>
#include <sys/prctl.h>
#include "mutex.hpp"
#include "Log.hpp"
const int gThreadNum = 5;
template <class T>
class ThreadPool
{

public:
  ~ThreadPool()
  {
    pthread_mutex_destroy(&_mutex);
    pthread_cond_destroy(&_cond);
  }

public:
  static ThreadPool<T> *getInstance()
  {
    static Mutex m;
    if (instance == nullptr)
    {
      Lock_GUARD l(&m);
      // 有线程安全问题 -- 可以加锁解决
      if (instance == nullptr) // 单例不存在
      {
        instance = new ThreadPool<T>();
      }
      // 出了代码块就是自动解锁
    }

    return instance;
  }
  // 每一个线程都会来到这里
  static void *threadRoutine(void *args) // 主要是 this指针
  {
    prctl(PR_SET_NAME, "follower"); // 修改线程名字
    // 线程分离
    pthread_detach(pthread_self());
    // this指针
    ThreadPool *tp = (ThreadPool *)args;
    while (true)
    {
      // sleep(1);
      // std::cout << "thread [" << pthread_self() << "] running..." << std::endl;
      tp->lockQueue();
      while (!tp->haveTask())
      {
        // 进来是没有任务,都给我去等着
        tp->waitForTask();
      }
      // 此时 有任务了
      T t = tp->pop();
      tp->unlockQueue();

      // 这里应该封装成一个函数,处理任务的的函数,我们暂时这里保存一下,后面网络的时候要用
      // t();
      t();
    }
  }

public:
  void start()
  {
    assert(!_isStart);

    for (size_t i = 0; i < _threadNum; i++)
    {
      pthread_t temp;
      // 创建线程
      pthread_create(&temp, nullptr, threadRoutine, this);
    }
    _isStart = true;
  }
  // 放任务
  void push(const T &in)
  {
    lockQueue();
    _taskQueue.push(in);

    // 选择线程持处理任务
    choiceThreadForHandler();
    // 这里为何不会死锁,很简单,我们所有的线程在阻塞等待的时候,等待的时候锁已经被放走了,我们一旦拿到任务,首先拿到锁,继续执行,说实话后面的解锁感觉没有必要,这里保存下来也是不错的.
    unlockQueue();
  }

private:
  ThreadPool(int num = gThreadNum)
      : _threadNum(num), _isStart(false)
  {
    pthread_mutex_init(&_mutex, nullptr);
    pthread_cond_init(&_cond, nullptr);
  }

  ThreadPool(const ThreadPool<T> &t) = delete;
  ThreadPool<T> &operator=(const ThreadPool<T> &t) = delete;

  // 告知一个线程来处理任务了
  void choiceThreadForHandler()
  {
    pthread_cond_signal(&_cond);
  }

  // 没有任务,都在这里等这
  void waitForTask()
  {
    pthread_cond_wait(&_cond, &_mutex);
  }
  // 是否有任务
  bool haveTask()
  {
    return !_taskQueue.empty();
  }
  T pop()
  {
    T ret = _taskQueue.front();
    _taskQueue.pop();
    return ret;
  }
  void lockQueue()
  {
    pthread_mutex_lock(&_mutex);
  }
  void unlockQueue()
  {
    pthread_mutex_unlock(&_mutex);
  }

private:
  bool _isStart;
  int _threadNum;
  std::queue<T> _taskQueue;
  pthread_mutex_t _mutex;
  pthread_cond_t _cond;

  static ThreadPool<T> *instance;
};

template <class T>
ThreadPool<T> *ThreadPool<T>::instance = nullptr;

#endif