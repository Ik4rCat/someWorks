#include <iostream>
using namespace std;

class AlarmClock {
  private:
    int currentHour, currentMinute;
    int alarmHour,   alarmMinute;
    bool alarmEnabled;
  public:
    AlarmClock() : currentHour(0), currentMinute(0),
                   alarmHour(0),   alarmMinute(0),
                   alarmEnabled(false) {}

    void setTime(int h, int m) {
        if (h >= 0 && h < 24 && m >= 0 && m < 60) {
            currentHour   = h;
            currentMinute = m;
        } else {
            cout << "Ошибка: некорректное время" << endl;
        }
    }

    void setAlarm(int h, int m) {
        if (h >= 0 && h < 24 && m >= 0 && m < 60) {
            alarmHour    = h;
            alarmMinute  = m;
            alarmEnabled = true;
        } else {
            cout << "Ошибка: некорректное время будильника" << endl;
        }
    }

    void tick() {
        currentMinute++;
        if (currentMinute >= 60) {
            currentMinute = 0;
            currentHour++;
            if (currentHour >= 24)
                currentHour = 0;
        }
        showTime();
        if (alarmEnabled && currentHour == alarmHour && currentMinute == alarmMinute)
            cout << "*** БУДИЛЬНИК! Пора вставать! ***" << endl;
    }

    void showTime() {
        cout << "Время: "
             << (currentHour   < 10 ? "0" : "") << currentHour   << ":"
             << (currentMinute < 10 ? "0" : "") << currentMinute << endl;
    }
};

int main() {
    AlarmClock clock;
    clock.setTime(7, 58);
    clock.setAlarm(8, 0);

    cout << "Тикаем..." << endl;
    clock.tick();
    clock.tick();
    clock.tick();

    return 0;
}
