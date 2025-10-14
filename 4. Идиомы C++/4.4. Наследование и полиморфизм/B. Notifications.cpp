#include <string>

class NotifierBase {
   public:
    virtual void Notify(const std::string& message) const = 0;
    virtual ~NotifierBase() = default;
};

class SmsNotifier : public NotifierBase {
   private:
    std::string number_;

   public:
    explicit SmsNotifier(const std::string& number) : number_(number) {
    }

    void Notify(const std::string& message) const override {
        SendSms(number_, message);
    }
};

class EmailNotifier : public NotifierBase {
   private:
    std::string email_;

   public:
    explicit EmailNotifier(const std::string& email) : email_(email) {
    }

    void Notify(const std::string& message) const override {
        SendEmail(email_, message);
    }
};