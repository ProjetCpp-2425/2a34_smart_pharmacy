#ifndef STAFF_H
#define STAFF_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Staff
{

    QString login, password, firstName, lastName, email, role, gender;
    int id, cin, phone, salary;
    QString dob, hireDate;

public:

    Staff();
    Staff(int id, int cin, QString login, QString password, QString firstName, QString lastName, QString email,
          QString role, int phone, QString gender, int salary, QString dob, QString hireDate);


    int getId() const { return id; }
    int getCin() const { return cin; }
    QString getLogin() const { return login; }
    QString getPassword() const { return password; }
    QString getFirstName() const { return firstName; }
    QString getLastName() const { return lastName; }
    QString getEmail() const { return email; }
    QString getRole() const { return role; }
    int getPhone() const { return phone; }
    QString getGender() const { return gender; }
    int getSalary() const { return salary; }
    QString getDob() const { return dob; }
    QString getHireDate() const { return hireDate; }


    void setId(int newId) { id = newId; }
    void setCin(int newCin) { cin = newCin; }
    void setLogin(QString newLogin) { login = newLogin; }
    void setPassword(QString newPassword) { password = newPassword; }
    void setFirstName(QString newFirstName) { firstName = newFirstName; }
    void setLastName(QString newLastName) { lastName = newLastName; }
    void setEmail(QString newEmail) { email = newEmail; }
    void setRole(QString newRole) { role = newRole; }
    void setPhone(int newPhone) { phone = newPhone; }
    void setGender(QString newGender) { gender = newGender; }
    void setSalary(int newSalary) { salary = newSalary; }
    void setDob(QString newDob) { dob = newDob; }
    void setHireDate(QString newHireDate) { hireDate = newHireDate; }


    bool add();
    QSqlQueryModel* display();
    bool modify(int id, QString login, QString password, QString firstName, QString lastName, QString email,
                QString role, int phone, QString gender, int salary, QString dob, QString hireDate);
    bool remove(int id);
    bool exists(int id);
   /// bool update();  // Declare the update function

    bool validateEmail(const QString& email);
    bool validatePhone(int phone);
    bool validateSalary(int salary);
};

#endif
