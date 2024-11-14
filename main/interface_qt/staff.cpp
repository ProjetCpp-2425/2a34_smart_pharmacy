#include "staff.h"
#include "qregularexpression.h"
#include "qsqlerror.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QVariant>
#include <QDebug>
#include <QSqlError>
// Default constructor
Staff::Staff() : id(0), cin(0), phone(0), salary(0) {}

// Parameteri constructor
Staff::Staff(int id, int cin, QString login, QString password, QString firstName, QString lastName, QString email,
             QString role, int phone, QString gender, int salary, QString dob, QString hireDate) {
    this->id = id;
    this->cin = cin;
    this->login = login;
    this->password = password;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->role = role;
    this->phone = phone;
    this->gender = gender;
    this->salary = salary;
    this->dob = dob;
    this->hireDate = hireDate;
}

// Method to add a staff member
bool Staff::add() {
    QSqlQuery query;
    query.prepare("INSERT INTO staff (id, cin, login, password, firstName, lastName, email, role, phone, gender, salary, dob, hireDate) "
                  "VALUES (:id, :cin, :login, :password, :firstName, :lastName, :email, :role, :phone, :gender, :salary, TO_DATE(:dob, 'YYYY-MM-DD'), TO_DATE(:hireDate, 'YYYY-MM-DD'))");
    query.bindValue(":id", id);
    query.bindValue(":cin", cin);
    query.bindValue(":login", login);
    query.bindValue(":password", password);
    query.bindValue(":firstName", firstName);
    query.bindValue(":lastName", lastName);
    query.bindValue(":email", email);
    query.bindValue(":role", role);
    query.bindValue(":phone", phone);
    query.bindValue(":gender", gender);
    query.bindValue(":salary", salary);
    query.bindValue(":dob", dob);
    query.bindValue(":hireDate", hireDate);

    bool result = query.exec();
    if (!result) {
            qDebug() << "Database insertion error:" << query.lastError().text();
        } else {
            qDebug() << "Staff member added successfully!";
        }
    return result;
}

// Method to display staff members
QSqlQueryModel* Staff::display() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM staff");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Login"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Password"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("First Name"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Last Name"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Role"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Phone"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("Gender"));
    model->setHeaderData(10, Qt::Horizontal, QObject::tr("Salary"));
    model->setHeaderData(11, Qt::Horizontal, QObject::tr("Date of Birth"));
    model->setHeaderData(12, Qt::Horizontal, QObject::tr("Hire Date"));

    return model;
}

// Method to delete a staff member by ID
bool Staff::remove(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM staff WHERE id = :id");
    query.bindValue(":id", id);
    bool result = query.exec();
    if (!result) {
        qDebug() << "Database deletion error:" << query.lastError().text();
    }
    return result;
}

// Method to modify a staff member's details
bool Staff::modify(int id, QString login, QString password, QString firstName, QString lastName, QString email,
                   QString role, int phone, QString gender, int salary, QString dob, QString hireDate) {
    QSqlQuery query;
    query.prepare("UPDATE staff SET login = :login, password = :password, firstName = :firstName, "
                  "lastName = :lastName, email = :email, role = :role, phone = :phone, gender = :gender, "
                  "salary = :salary, dob = :dob, hireDate = :hireDate WHERE id = :id");
    query.bindValue(":login", login);
    query.bindValue(":password", password);
    query.bindValue(":firstName", firstName);
    query.bindValue(":lastName", lastName);
    query.bindValue(":email", email);
    query.bindValue(":role", role);
    query.bindValue(":phone", phone);
    query.bindValue(":gender", gender);
    query.bindValue(":salary", salary);
    query.bindValue(":dob", dob);
    query.bindValue(":hireDate", hireDate);
    query.bindValue(":id", id);

    bool result = query.exec();
    if (!result) {
        qDebug() << "Database modification error:" << query.lastError().text();
    }
    return result;
}

// Method to check if a staff member exists by ID
bool Staff::exists(int id) {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM staff WHERE id = :id");
    query.bindValue(":id", id);
    if (query.exec() && query.next()) {
        return query.value(0).toInt() > 0;
    }
    return false;
}

// Optional: Additional validation methods (example for email)
bool Staff::validateEmail(const QString& email) {
    QRegularExpression emailRegex(R"(^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$)");
    return emailRegex.match(email).hasMatch();
}

// Optional: Phone validation (example assuming 8-digit number)
bool Staff::validatePhone(int phone) {
    return QString::number(phone).length() == 8;
}

// Optional: Salary validation (positive integer check)
bool Staff::validateSalary(int salary) {
    return salary > 0;
}




//// update staff

