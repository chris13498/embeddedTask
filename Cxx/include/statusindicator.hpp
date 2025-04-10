#ifndef STATUSINDICATOR_HPP
#define STATUSINDICATOR_HPP

class StatusIndicator { 
public:
    static void init();
    static void resetState();
    static void showOk();
    static void showWarning();
    static void showCritical();
};


#endif // STATUSINDICATOR_HPP