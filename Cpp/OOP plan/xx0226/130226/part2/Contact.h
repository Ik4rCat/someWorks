#pragma once

#include <iostream>
#include <cstring>

using namespace std;

class Contact {
private:
    char* fullName;
    char homePhone[20];
    char workPhone[20];
    char mobilePhone[20];
    char additionalInfo[100];

public:
    Contact();
    Contact(const char* fullName, const char* homePhone, const char* workPhone, const char* mobilePhone, const char* additionalInfo);
    Contact(const Contact& other);
    ~Contact();
    
    inline const char* getFullName() const { return fullName; }
    inline const char* getHomePhone() const { return homePhone; }
    inline const char* getWorkPhone() const { return workPhone; }
    inline const char* getMobilePhone() const { return mobilePhone; }
    inline const char* getAdditionalInfo() const { return additionalInfo; }
    
    void setFullName(const char* fullName);
    void setHomePhone(const char* phone);
    void setWorkPhone(const char* phone);
    void setMobilePhone(const char* phone);
    void setAdditionalInfo(const char* info);
    
    void input();
    void output() const;
};
