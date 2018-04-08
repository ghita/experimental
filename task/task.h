#ifndef EXPERIMENTAL_TASK_H
#define EXPERIMENTAL_TASK_H

#include <memory>
#include <functional>

template<typename T, typename... Args>
class task;

template <typename R, typename... Args>
class task<R(Args...)>
{
 public:
    template <class F>
    task(F&& f): m_p(std::make_unique<model<F>>(std::forward<F>(f))){}

    R operator()(Args... args)
    {
        return m_p->_invoke(args...);
    }
    ~task() = default;

 private:
    class concept
    {
     public:
        virtual ~concept() = default;
        virtual R _invoke(Args&&...) = 0;
    };

    template <typename F>
    class model: public concept
    {
     public:
        template <class G>
        explicit model(G&& f): m_f(std::forward<G>(f)) {}

        R _invoke(Args&&... args) override
        {
            return m_f(args...);
        }

     private:
        F m_f;
    };

    std::unique_ptr<concept> m_p;
};

#endif //EXPERIMENTAL_TASK_H
