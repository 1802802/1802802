#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>

class MyClass : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString userName READ getUsername WRITE setUserName NOTIFY userNameChanged)
public:
    explicit MyClass(QObject *parent = 0);
    QString getUsername() const
    {
        return m_userName;
    }
    void setUserName(QString userName)
    {
        m_userName = userName;
        emit userNameChanged(userName);  //发出信号
    }

signals:
    void userNameChanged(QString);

private:
        QString m_userName;   //自己的私有成员，存储名字

public slots:
};

#endif // MYCLASS_H
