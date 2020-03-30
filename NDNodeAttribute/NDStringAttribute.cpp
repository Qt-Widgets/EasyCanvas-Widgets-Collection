#include "NDStringAttribute.h"

NDStringAttribute::NDStringAttribute(NDNodeBase* parentNode)
    :NDAttributeBase(parentNode)
{

}

NDStringAttribute::~NDStringAttribute()
{

}

void NDStringAttribute::setCurrentValue(const QString& value)
{
    bool needSendSignal = true;
    if (m_string == value)
        needSendSignal = false;

    m_string = value;
    if (needSendSignal)
        emit valueChanged(value);
}

QString NDStringAttribute::getCurrentValue(void)
{
    return m_string;
}

// 设置/获取是否显示按钮
void NDStringAttribute::setShowButton(bool isShow)
{
    m_isShowButton = isShow;
}

bool NDStringAttribute::isShowButton(void)
{
    return m_isShowButton;
}

// 设置/获取按钮名字
void NDStringAttribute::setButtonString(const QString& buttonName)
{
    m_buttonString = buttonName;
}

QString NDStringAttribute::getButtonString(void)
{
    return m_buttonString;
}

// 设置按钮的功能
void NDStringAttribute::setButtonFunction(std::function<bool(QString&)> func)
{
    m_buttonFunc = func;
}

std::function<bool(QString&)> NDStringAttribute::getButtonFunction(void)
{
    return m_buttonFunc;
}
