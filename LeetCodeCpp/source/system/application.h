#pragma once
#include "system/Time.h"
class App {

public:
    static App* getApp() {
       if(s_Instance)
            return s_Instance;
       else {
           s_Instance = new App();
           return s_Instance;
       }
    }

    // 禁用拷贝构造函数和赋值运算符
    App(const App&) = delete;
    App& operator=(const App&) = delete;

private:
    App() {}
    ~App() {}
    static App* s_Instance;
    static std::vector<ProfileMessage> s_profile;
};